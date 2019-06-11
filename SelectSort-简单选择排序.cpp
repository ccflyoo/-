#include <stdio.h>

void BulleSort_1(int R[],int n)
{
	int i,j;
	int temp,min;
	for(i=0;i<n-1;i++)
	{
		min=i;
		for(j=i+1;j<n;j++)
		{
			if(R[j]<R[min])
				min=j;
		}
		if(min!=i)
		{
			temp=R[i];
			R[i]=R[min];
			R[min]=temp;
		}
	}
}

int main()
{
	int i;
	int R[9]={6,54,3,90,33,7,1,99,44};
	BulleSort_1(R,9);
	for(i=0;i<9;i++)
		printf("%d  ",R[i]);
	return 0;
}
