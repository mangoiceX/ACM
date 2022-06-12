/*
Ŀ��:
��װ
1.��inputFile�ļ��е����ݷ�װ��MAC֡,��װ�õ�MAC֡д��outputFile�ļ���.
2.������ݳ���С��46�ֽ�,��ȫ��46�ֽ�
3.������ݳ��ȴ���1500,���װ�ɶ��MAC֡
���װ:
��ȡoutputFile�е�����,�������ʾ֡����Ϣ
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXSIZE 10
#define MINSIZE 3
unsigned int  crc8(char *ptr,int len)
/*
CRCУ��,ptr����Ҫ����������׵�ַ,len����Ҫ����ĳ���
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
/*֡��װ����*/
{
    char src[18];
	char des[18];
   
	int i,dataCrc,nu,j,lastNu,sum;
	FILE *fpIn,*fpOut;
	
	char data[MAXSIZE];
	char type[4];
	if((fpIn=fopen("inputFile.txt","a+"))==NULL)
	{
		printf("���ļ�ʧ��!");
		return 1;
	}
	if((fpOut=fopen("outputFile.txt","wb"))==NULL)
	{
		printf("д���ļ�ʧ��");
		return 1;
	}
 
	fseek(fpIn,0,SEEK_END);
	sum=ftell(fpIn);//���ݳ��� 
	
	nu=sum/MAXSIZE;//nu+1Ϊ֡�ĸ��� 
	int xnum=MINSIZE-(sum-nu*MAXSIZE);
	int flag;
	if(sum % MAXSIZE==0) flag=0;
	else flag=1;
 
    rewind(fpIn);
    
 	//printf("������Ŀ��MAC����ʽ��01-01-01-01-01-01��:");
    //gets(des);
    strcpy(des,"01-01-01-01-01-01");
    strcpy(src,"02-02-01-01-01-01");
    
//	printf("������ԴMAC:");
//	gets(src);
	
//	printf("�����������ֶ�:");
	
//	scanf("%c%c%c%c",type,type+1,type+2,type+3);
//	if(strcmp(type,"0800") == 0 || strcmp(type,"8737") == 0)

    strcpy(type,"0800");
	printf("��װok");
//	else
//	{
//		printf("������������ʹ������������룺");
//		scanf("%s",type);	
//	}
	  
 
	for(j=0;j<nu+1;j++)
	{
		if((j!=nu)|| (j==nu && flag==1))
		{
			for(i=0;i<17;i++)
			{
				if(des[i]!='-')
				  fputc(des[i],fpOut);    //д��Ŀ��MAC
			}
			for(i=0;i<17;i++)
			{
				if(src[i]!='-')
				  fputc(src[i],fpOut);   //д��ԴMAC
			}
			
			fputs(type,fpOut);     //д�����ͺ�
		}
		
 
 
		if(j!=nu)
		/*�������һ������,��ǰ������ݶ�Ӧ����maxsize*/
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
			fseek(fpOut,0,SEEK_END);//ÿһ֡������־Ϊ�� 
			fputc('|',fpOut);
		}
		else if(j==nu && flag==1)
		{
			//���һ������,��Ҫ���⴦��,��ȡ����
			lastNu=ftell(fpIn);
			fread(data,sizeof(char),sum-lastNu,fpIn);
				
			fwrite(data,sizeof(char),sum-lastNu,fpOut);printf("%s\n",data);
			dataCrc=crc8(data,sum-lastNu);
			
			if(xnum>0)
	        {
		        for(i=0;i<xnum;i++)
			       fputc('x',fpOut);   //�������,�����
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
			fseek(fpOut,0,SEEK_END);//ÿһ֡������־Ϊ| 
			fputc('|',fpOut);
		}
	}
	
	fclose(fpIn);
	fclose(fpOut);
 
 
	return 0;
}

int unpack()
/*���װ����*/
{	
	int i,dataStart,dataEnd,dataLen,sum,j,nu;
	int srcCrc=0,nowCrc=0;
	char outdata[MAXSIZE];
	char outsrc[12],outdes[12],outtype[4];
	FILE *fpOut;
	if((fpOut=fopen("outputFile.txt","rb"))==NULL)
	{
		printf("���ļ�ʧ��!");
		return 1;
	}
 
	fseek(fpOut,0,SEEK_END);
	sum=ftell(fpOut);//�ڷ�װ���ļ�������֡�ĳ��� 
	rewind(fpOut);
 
    printf("�����ܳ���(����IP��)��");
	scanf("%d",&dataLen);
	nu=dataLen/MAXSIZE;//֡��Ϊnu+1 
	int flag;
	if(dataLen % MAXSIZE==0) 
		flag=0;
	else 
		flag=1;
 
	
	for(j=0;j<nu+1;j++)
		/*ѭ�����������ݳ���1500֡����Ϣ*/
	{
		if((j!=nu)|| (j==nu && flag==1))
		{
			printf("\n��%d֡��\n",j+1);
		
			fread(outdes,sizeof(char),12,fpOut);
			printf("Ŀ�ĵ�ַ��");
			for(int i=0;i<12;i++)
			{
				printf("%c",outdes[i]);
				if(i%2==1 && i!=11)
				  printf("-");
			}
			printf("\n");
			  
			fread(outsrc,sizeof(char),12,fpOut);
			printf("Դ��ַ��");
			for(int i=0;i<12;i++)
			{
				printf("%c",outsrc[i]);
				if(i%2==1 && i!=11)
				  printf("-");
			}
			printf("\n");
			
		    fread(outtype,sizeof(char),4,fpOut);
			printf("���ͣ�");
			for(int i=0;i<4;i++)
			{
				printf("%c",outtype[i]);
			}
			printf("\n");
		}
		
		
		int offset=1;
		if(j==nu)
	     {
		    //���һ��֡,���⴦��
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
			}//�ļ�crc 
		
			nowCrc=crc8(outdata,dataLen-nu*MAXSIZE);//�������CRC 
		    
		 }
		else
		{
			//�������һ��֡
			fread(outdata,sizeof(char),MAXSIZE,fpOut);
			char x=fgetc(fpOut);
			while(x>='0' && x<='9')
			{	
					srcCrc*= 10; 
				    srcCrc+=x-48;
				    //offset*=10;
				    x=fgetc(fpOut);
			}//�ļ�crc 
			
			nowCrc=crc8(outdata,MAXSIZE);//�������CRC 
		}
		
		if((j!=nu)|| (j==nu && flag==1))
		{
			printf("\n����CRC:  %d",nowCrc);
			printf("\n������CRC:  %d",srcCrc);
			if (nowCrc==srcCrc) //�Ƚ�CRC,�Ƿ����
				printf("\n\n����\n");
			else
				printf("\n\n����\n");
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
	printf("���ȷ�װ(inputFile.txt�����Ѵ��ڣ���ҪMAC��ַ��������������)\n"); 
	pack();
	
	printf("\n���װ����1��\n"); 
	scanf("%d",&flag);
	if(flag==1) 
	  unpack();
	else
	  return 0;
}

