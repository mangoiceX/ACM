#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string> 
#include<cstring>
#include<set>
#define INF 0x7fffffff
using namespace std;
const int maxn = 50000 + 10;
//�߶����ʺϽ�������ڵ��������Ϣ���Ա��ϲ�����������Ĳ��������Ϣ��������
//����ĸ������0ʱ������ ��2*i+1,�к�����2*i+2 
//����ĸ������1ʱ������ ��2*i,�к�����2*i+1
struct SegTreeNode{
	int min,max;
	int add_mark;//�ӳٱ�� 
	int l ,r;
}seg_tree[maxn*4];//�����߶��� 
int arr[maxn];
/* 
���ܣ������߶���
 root����ǰ�߶����ĸ��ڵ��±�
 arr: ���������߶���������
 istart���������ʼλ��
 iend������Ľ���λ��
*/
void build(int root,int is,int ie){ //�ݹ鹹���߶��� 
	seg_tree[root].l = is,seg_tree[root].r = ie;
	
	if(is == ie){		//Ҷ�ӽ�� 
		seg_tree[root].min = arr[is];
		seg_tree[root].max = arr[is];
	}else{
		int mid = (ie - is)/2 + is;
		build(root * 2,is,mid);//�ݹ鹹�������� 
		build(root * 2 + 1, mid + 1,ie);//�ݹ鹹�������� 
		//������������������ֵ�����µ�ǰ���ڵ��ֵ 
		seg_tree[root].min = min(seg_tree[root*2].min,seg_tree[root*2+1].min);
		seg_tree[root].max = max(seg_tree[root*2].max,seg_tree[root*2+1].max);
			
	}
		
}

/*
2 ���ܣ��߶����������ѯ
3 root����ǰ�߶����ĸ��ڵ��±�
4 [nstart, nend]: ��ǰ�ڵ�����ʾ������
5 [qstart, qend]: �˴β�ѯ������
6 */
 
int query_min(int root,int qstart,int qend){//�߶����������ѯ 
	int nstart = seg_tree[root].l,nend = seg_tree[root].r;
	//��ѯ�����뵱ǰ����û�н���ʱ 
	if(nend < qstart || nstart > qend){
		return INF;
	//��ǰ��������ڲ�ѯ������ 
	}else if(nstart >= qstart && nend <= qend){
		return seg_tree[root].min;
	//��ǰ���䲿�ְ����ڲ�ѯ������ 
	}else{
		//int mid = (nend - nstart)/2 + nstart;
		//�ֱ������������������ѯ���������߲�ѯ����Ľ�Сֵ 
		return min( query_min(root*2,qstart,qend),
		query_min(root*2+1,qstart,qend) );
	}
	
}
	
int query_max(int root,int qstart,int qend){//�߶����������ѯ 
	int nstart = seg_tree[root].l,nend = seg_tree[root].r;
	//��ѯ�����뵱ǰ����û�н���ʱ 
	if(nend < qstart || nstart > qend){
		return 0;
	//��ǰ��������ڲ�ѯ������ 
	}else if(nstart >= qstart && nend <= qend){
		return seg_tree[root].max;
	//��ǰ���䲿�ְ����ڲ�ѯ������ 
	}else{
		//push_down(root); //----�ӳٱ�־�����´���
		
		//int mid = (nend - nstart)/2 + nstart;
		//�ֱ������������������ѯ���������߲�ѯ����Ľ�Сֵ 
		return max( query_max(root*2,qstart,qend),
		query_max(root*2+1,qstart,qend) );
	}
	
}

int main(){
	
	int n = 0,q = 0,s = 0,e = 0;
	while(scanf("%d %d",&n,&q) != EOF){
		
	
	for(int i = 1;i <= n;++i){
		scanf("%d",&arr[i]);
	}
	build(1,1,n);
	for(int i = 0;i < q;++i){
		scanf("%d %d",&s,&e);
		printf("%d\n",query_max(1,s,e) - query_min(1,s,e));
	}
}
	
	return 0;
}
