#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<iostream>
using namespace std;
#define Status int
#define ElemType int
//单链表结点数据结构
typedef struct LNode
{
	ElemType data;//数据域
	struct LNode *next;//指针域
}LNode,*LinkList;
//**************************基本操作函数***************************//
//初始化函数
Status InitList(LinkList &L)
{
 	L= new LNode;//生成头结点 这样删除等操作就不必分第一个结点和其他了
 	L->next = NULL;
 	return 1;
}
//获取单链表长度 头结点无数据，不算
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
//插入函数--后插法
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
		printf("插入位置无效！！！\n");
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
//删除函数 删除位置i的结点
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
		printf("删除位置无效！！！\n");
		return false;
	}
	else
	{
		q=p->next;
		p->next=q->next;
		free(q);//释放空间
		return true;
	}
}
//查找函数 按值查找 
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
//**************************功能实现函数**************************//
//遍历输出函数
void PrintList(LinkList L)
{
	LinkList p=L->next;//跳过头结点
	if(ListLength(L))
	{
		printf("当前单链表所有元素:");
		while(p)
		{
			printf("%d ",p->data);
			p=p->next;
		}
		printf("\n");
	}
	else
	{
		printf("当前单链表已空！\n");
	}
}
//插入功能函数 调用ListInsert后插
void Insert(LinkList &L)
{
  int place;ElemType e;bool flag;
  printf("请输入要插入的位置(从1开始)及元素:\n");
  scanf("%d%d",&place,&e);
  flag=ListInsert(L,place,e);
  if(flag) 
  {
	printf("插入成功！！！\n");
	PrintList(L);
  }
}
//删除功能函数 调用ListDelete删除
void Delete(LinkList L)
{
  int place;bool flag;
  printf("请输入要删除的位置(从1开始):\n");
  scanf("%d",&place);
  flag=ListDelete(L,place);
  if(flag) 
  {
	printf("删除成功！！！\n");
	PrintList(L);
  }
}
//查找功能函数 调用LocateElem查找
void Search(LinkList L)
{
  ElemType e;int sum,Len;
  printf("请输入要查找的值:\n");
  scanf("%d",&e);
  sum=LocateElem(L,e);
  Len=ListLength(L);
  if(sum!=0&&sum<=Len) 
  {
	printf("该值的位序为%d！\n",sum);
  }
  else
	printf("未找到该元素！\n");
}

void Len(LinkList L)
{
	int Len;
	Len=ListLength(L);
	printf("当前链表长度：%d！\n",Len);	
} 
 
//菜单
void menu()
{
   printf("********1.后插         2.删除*********\n");
   printf("********3.查值的序     4.输出*********\n");
   printf("********5.长度         6.退出*********\n"); 
}
//主函数
int main()
{
 LinkList L;int choice;
 InitList(L);
 while(1)
 {
  menu();
  printf("请输入菜单序号：\n");
  scanf("%d",&choice);
  if(choice==6) break;
  switch(choice)
  {
  case 1:Insert(L);break;
  case 2:Delete(L);break;
  case 3:Search(L);break;
  case 4:PrintList(L);break;
  case 5:Len(L);break;
  default:printf("输入错误！！！\n");
  }
 }
 return 0;
}

