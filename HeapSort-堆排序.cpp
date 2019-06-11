#include <stdio.h>
void Sift (int R[],int low,int high)
{
	int i=low,j=2*i;							//R[0]没有用，因为在这里得不到值 
	int temp=R[i];
	while(j<=high)
	{
		if(j<high&&R[j]<R[j+1])
			j++;
		if(R[j]>temp)
		{
			R[i]=R[j];
			i=j;
			j=2*i;
		}
		else
			break;
	}
	R[i]=temp;
 } 
 
void HeapSort(int R[],int n)
{
	int i,temp;
	for(i=n/2;i>=1;i--)							//初始化，从下向上建堆，从上向下调整，—— 
		Sift(R,i,n);							//——最后得出第一个最大堆顶元素
	for(i=n;i>=2;i--)							//将所有顶点推到堆顶，并向下排序 
	{
		temp=R[1];
		R[1]=R[i];
		R[i]=temp;
		Sift(R,1,i-1);							//将新插入到堆顶的数找到合适位置 
	}
}

int main()
{
	int i;
	int R[10]={0,6,54,3,90,33,7,1,99,44};		//需要排序9个数，要定义10个的数组—— 
	HeapSort(R,9);								//——传入n等于9，数组的定义与下标表示不同！ 
	for(i=1;i<10;i++)
		printf("%d  ",R[i]);
	return 0;
}
