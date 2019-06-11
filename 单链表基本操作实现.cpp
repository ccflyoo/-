#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<iostream>
using namespace std;
#define Status int
#define ElemType int
//�����������ݽṹ
typedef struct LNode
{
	ElemType data;//������
	struct LNode *next;//ָ����
}LNode,*LinkList;
//**************************������������***************************//
//��ʼ������
Status InitList(LinkList &L)
{
 	L= new LNode;//����ͷ��� ����ɾ���Ȳ����Ͳ��طֵ�һ������������
 	L->next = NULL;
 	return 1;
}
//��ȡ�������� ͷ��������ݣ�����
int ListLength(LinkList L)
{
	LinkList p=L;int sum=0;
	while(p)
	{
	 sum++;
	 p=p->next;
	}
	return sum-1;
}
//���뺯��--��巨
bool ListInsert(LinkList &L,int place,ElemType e)
{
	LinkList q;LinkList p=L;int i=0;
	while(p->next!=NULL&&i<place-1)
	{
	 p=p->next;
	 ++i;
	}
	if(i<place-1)
	{
		printf("����λ����Ч������\n");
		return false;
	}
	else
	{
		q=new LNode;
		q->data=e;
		q->next=p->next;
		p->next=q;
		return true;
	}
}
//ɾ������ ɾ��λ��i�Ľ��
bool ListDelete(LinkList &L,int place)
{
	LinkList p=L;int i=0;
	LinkList q;
	while(p->next!=NULL&&i<place-1)
	{
	 	p=p->next;
		++i;
	}
	if(p->next==NULL)
	{
		printf("ɾ��λ����Ч������\n");
		return false;
	}
	else
	{
		q=p->next;
		p->next=q->next;
		free(q);//�ͷſռ�
		return true;
	}
}
//���Һ��� ��ֵ���� 
int LocateElem(LinkList L,ElemType e)
{
	int sum=0;
	LNode *p=L;
	while(p->next!=NULL&&p->data!=e)
	{
		sum++;
		p=p->next;
	}
	return sum;
}
//**************************����ʵ�ֺ���**************************//
//�����������
void PrintList(LinkList L)
{
	LinkList p=L->next;//����ͷ���
	if(ListLength(L))
	{
		printf("��ǰ����������Ԫ��:");
		while(p)
		{
			printf("%d ",p->data);
			p=p->next;
		}
		printf("\n");
	}
	else
	{
		printf("��ǰ�������ѿգ�\n");
	}
}
//���빦�ܺ��� ����ListInsert���
void Insert(LinkList &L)
{
  int place;ElemType e;bool flag;
  printf("������Ҫ�����λ��(��1��ʼ)��Ԫ��:\n");
  scanf("%d%d",&place,&e);
  flag=ListInsert(L,place,e);
  if(flag) 
  {
	printf("����ɹ�������\n");
	PrintList(L);
  }
}
//ɾ�����ܺ��� ����ListDeleteɾ��
void Delete(LinkList L)
{
  int place;bool flag;
  printf("������Ҫɾ����λ��(��1��ʼ):\n");
  scanf("%d",&place);
  flag=ListDelete(L,place);
  if(flag) 
  {
	printf("ɾ���ɹ�������\n");
	PrintList(L);
  }
}
//���ҹ��ܺ��� ����LocateElem����
void Search(LinkList L)
{
  ElemType e;int sum,Len;
  printf("������Ҫ���ҵ�ֵ:\n");
  scanf("%d",&e);
  sum=LocateElem(L,e);
  Len=ListLength(L);
  if(sum!=0&&sum<=Len) 
  {
	printf("��ֵ��λ��Ϊ%d��\n",sum);
  }
  else
	printf("δ�ҵ���Ԫ�أ�\n");
}

void Len(LinkList L)
{
	int Len;
	Len=ListLength(L);
	printf("��ǰ�����ȣ�%d��\n",Len);	
} 
 
//�˵�
void menu()
{
   printf("********1.���         2.ɾ��*********\n");
   printf("********3.��ֵ����     4.���*********\n");
   printf("********5.����         6.�˳�*********\n"); 
}
//������
int main()
{
 LinkList L;int choice;
 InitList(L);
 while(1)
 {
  menu();
  printf("������˵���ţ�\n");
  scanf("%d",&choice);
  if(choice==6) break;
  switch(choice)
  {
  case 1:Insert(L);break;
  case 2:Delete(L);break;
  case 3:Search(L);break;
  case 4:PrintList(L);break;
  case 5:Len(L);break;
  default:printf("������󣡣���\n");
  }
 }
 return 0;
}

