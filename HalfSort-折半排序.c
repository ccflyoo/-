#include <stdio.h>

void HalfSort(int R[],int n)
{
	int low,high,temp;
	int i,j,m;
	for(i=1;i<n;i++)						//�ӵڶ���Ԫ�ؿ�ʼ 
	{
		low=0;high=i-1;
		while(low<=high)					//�Ƚ� 
		{
			m=(low+high)/2;
			if(R[m]<=R[i])
				low=m+1;
			else
				high=m-1;
		}
		temp=R[i];
		for(j=i-1;j>high;--j)				//�ƶ� 
			R[j+1]=R[j];
		R[high+1]=temp;
	}
}
int main()
{
	int i;
	int R[9]={6,54,3,90,33,7,1,99,44};
	HalfSort(R,9);
	for(i=0;i<9;i++)
		printf("%d  ",R[i]);
	return 0;
}
