/*
目标:
封装
1.将inputFile文件中的数据封装成MAC帧,封装好的MAC帧写入outputFile文件中.
2.如果数据长度小于46字节,则补全到46字节
3.如果数据长度大于1500,则封装成多个MAC帧
解封装:
读取outputFile中的数据,并逐个显示帧的信息
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXSIZE 10
#define MINSIZE 3
unsigned int  crc8(char *ptr,int len)
/*
CRC校验,ptr是需要计算的数组首地址,len是需要计算的长度
*/
{
    unsigned int  CRC = 0;
    unsigned int  i;
	
    while(len--){
        CRC = CRC^ *ptr++;
        for(i = 0; i < 8; i++){
            if(CRC & 0x01){
                CRC = (CRC >> 1 )^ 0x8c;
            }
			else{
				CRC >>= 1;
			}
        }                   
    }
	
    return CRC;  
}

int pack()
/*帧封装函数*/
{
    char src[18];
	char des[18];
   
	int i,dataCrc,nu,j,lastNu,sum;
	FILE *fpIn,*fpOut;
	
	char data[MAXSIZE];
	char type[4];
	if((fpIn=fopen("inputFile.txt","a+"))==NULL)
	{
		printf("打开文件失败!");
		return 1;
	}
	if((fpOut=fopen("outputFile.txt","wb"))==NULL)
	{
		printf("写入文件失败");
		return 1;
	}
 
	fseek(fpIn,0,SEEK_END);
	sum=ftell(fpIn);//数据长度 
	
	nu=sum/MAXSIZE;//nu+1为帧的个数 
	int xnum=MINSIZE-(sum-nu*MAXSIZE);
	int flag;
	if(sum % MAXSIZE==0) flag=0;
	else flag=1;
 
    rewind(fpIn);
    
 	//printf("请输入目标MAC（格式如01-01-01-01-01-01）:");
    //gets(des);
    strcpy(des,"01-01-01-01-01-01");
    strcpy(src,"02-02-01-01-01-01");
    
//	printf("请输入源MAC:");
//	gets(src);
	
//	printf("请输入类型字段:");
	
//	scanf("%c%c%c%c",type,type+1,type+2,type+3);
//	if(strcmp(type,"0800") == 0 || strcmp(type,"8737") == 0)

    strcpy(type,"0800");
	printf("封装ok");
//	else
//	{
//		printf("输入的数据类型错误，请重新输入：");
//		scanf("%s",type);	
//	}
	  
 
	for(j=0;j<nu+1;j++)
	{
		if((j!=nu)|| (j==nu && flag==1))
		{
			for(i=0;i<17;i++)
			{
				if(des[i]!='-')
				  fputc(des[i],fpOut);    //写入目的MAC
			}
			for(i=0;i<17;i++)
			{
				if(src[i]!='-')
				  fputc(src[i],fpOut);   //写入源MAC
			}
			
			fputs(type,fpOut);     //写入类型号
		}
		
 
 
		if(j!=nu)
		/*不是最后一个数据,则前面的数据都应该是maxsize*/
		{
			fread(data,sizeof(char),MAXSIZE,fpIn);
			
			fwrite(data,sizeof(char),MAXSIZE,fpOut);
			dataCrc=crc8(data,MAXSIZE);
			
			int crc=dataCrc;
			int k=0;
			int Crc[100];
			while(crc!=0)
			{ 
			   Crc[k]=crc%10;
			   crc=crc/10;  
			   k++;      
			}
			for(int q=k-1;q>=0;q--)
			{ 
			   fputc(char(Crc[q])+48,fpOut);   
			}
			fseek(fpOut,0,SEEK_END);//每一帧结束标志为！ 
			fputc('|',fpOut);
		}
		else if(j==nu && flag==1)
		{
			//最后一段数据,需要额外处理,获取长度
			lastNu=ftell(fpIn);
			fread(data,sizeof(char),sum-lastNu,fpIn);
				
			fwrite(data,sizeof(char),sum-lastNu,fpOut);printf("%s\n",data);
			dataCrc=crc8(data,sum-lastNu);
			
			if(xnum>0)
	        {
		        for(i=0;i<xnum;i++)
			       fputc('x',fpOut);   //如果不足,则填充
	        }
			int crc=dataCrc;
			int k=0;
			int Crc[100];
			while(crc!=0)
			{ 
			   Crc[k]=crc%10;
			   crc=crc/10;  
			   k++;      
			}
			for(int q=k-1;q>=0;q--)
			{ 
			   fputc(char(Crc[q])+48,fpOut);   
			}
			fseek(fpOut,0,SEEK_END);//每一帧结束标志为| 
			fputc('|',fpOut);
		}
	}
	
	fclose(fpIn);
	fclose(fpOut);
 
 
	return 0;
}

int unpack()
/*解封装函数*/
{	
	int i,dataStart,dataEnd,dataLen,sum,j,nu;
	int srcCrc=0,nowCrc=0;
	char outdata[MAXSIZE];
	char outsrc[12],outdes[12],outtype[4];
	FILE *fpOut;
	if((fpOut=fopen("outputFile.txt","rb"))==NULL)
	{
		printf("打开文件失败!");
		return 1;
	}
 
	fseek(fpOut,0,SEEK_END);
	sum=ftell(fpOut);//在封装后文件里所有帧的长度 
	rewind(fpOut);
 
    printf("数据总长度(来自IP层)：");
	scanf("%d",&dataLen);
	nu=dataLen/MAXSIZE;//帧数为nu+1 
	int flag;
	if(dataLen % MAXSIZE==0) 
		flag=0;
	else 
		flag=1;
 
	
	for(j=0;j<nu+1;j++)
		/*循环逐个输出数据长度1500帧的信息*/
	{
		if((j!=nu)|| (j==nu && flag==1))
		{
			printf("\n第%d帧：\n",j+1);
		
			fread(outdes,sizeof(char),12,fpOut);
			printf("目的地址：");
			for(int i=0;i<12;i++)
			{
				printf("%c",outdes[i]);
				if(i%2==1 && i!=11)
				  printf("-");
			}
			printf("\n");
			  
			fread(outsrc,sizeof(char),12,fpOut);
			printf("源地址：");
			for(int i=0;i<12;i++)
			{
				printf("%c",outsrc[i]);
				if(i%2==1 && i!=11)
				  printf("-");
			}
			printf("\n");
			
		    fread(outtype,sizeof(char),4,fpOut);
			printf("类型：");
			for(int i=0;i<4;i++)
			{
				printf("%c",outtype[i]);
			}
			printf("\n");
		}
		
		
		int offset=1;
		if(j==nu)
	     {
		    //最后一个帧,额外处理
			fread(outdata,sizeof(char),dataLen-nu*MAXSIZE,fpOut);
			
			
			
			if(dataLen-nu*MAXSIZE<MINSIZE)
			{
				fseek(fpOut,MINSIZE-(dataLen-nu*MAXSIZE),SEEK_CUR);
			}
    
            
			char x=fgetc(fpOut);
			while(x>='0' && x<='9')
			{	
					srcCrc*= 10; 
				    srcCrc+=x-48;
				    //offset*=10;
				    x=fgetc(fpOut);
			}//文件crc 
		
			nowCrc=crc8(outdata,dataLen-nu*MAXSIZE);//现在求的CRC 
		    
		 }
		else
		{
			//不是最后一个帧
			fread(outdata,sizeof(char),MAXSIZE,fpOut);
			char x=fgetc(fpOut);
			while(x>='0' && x<='9')
			{	
					srcCrc*= 10; 
				    srcCrc+=x-48;
				    //offset*=10;
				    x=fgetc(fpOut);
			}//文件crc 
			
			nowCrc=crc8(outdata,MAXSIZE);//现在求的CRC 
		}
		
		if((j!=nu)|| (j==nu && flag==1))
		{
			printf("\n本次CRC:  %d",nowCrc);
			printf("\n传来的CRC:  %d",srcCrc);
			if (nowCrc==srcCrc) //比较CRC,是否出错
				printf("\n\n接受\n");
			else
				printf("\n\n丢弃\n");
		} 
		
			
		fseek(fpOut,0,SEEK_CUR);
		srcCrc=0;	
	} 
					
	fclose(fpOut);
	return 0;
}

int main()
{
	int flag; 
	printf("首先封装(inputFile.txt内容已存在，需要MAC地址和数据类型输入)\n"); 
	pack();
	
	printf("\n解封装输入1：\n"); 
	scanf("%d",&flag);
	if(flag==1) 
	  unpack();
	else
	  return 0;
}

