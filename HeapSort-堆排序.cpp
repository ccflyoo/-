#include <stdio.h>
void Sift (int R[],int low,int high)
{
	int i=low,j=2*i;							//R[0]û���ã���Ϊ������ò���ֵ 
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
	for(i=n/2;i>=1;i--)							//��ʼ�����������Ͻ��ѣ��������µ��������� 
		Sift(R,i,n);							//�������ó���һ�����Ѷ�Ԫ��
	for(i=n;i>=2;i--)							//�����ж����Ƶ��Ѷ������������� 
	{
		temp=R[1];
		R[1]=R[i];
		R[i]=temp;
		Sift(R,1,i-1);							//���²��뵽�Ѷ������ҵ�����λ�� 
	}
}

int main()
{
	int i;
	int R[10]={0,6,54,3,90,33,7,1,99,44};		//��Ҫ����9������Ҫ����10�������顪�� 
	HeapSort(R,9);								//��������n����9������Ķ������±��ʾ��ͬ�� 
	for(i=1;i<10;i++)
		printf("%d  ",R[i]);
	return 0;
}
