#include <stdio.h>

void BulleSort(int R[],int n)
{
	int i,j;
	int temp,flag;
	for(i=0;i<n-1;i++)			
	{
		flag=0;
		for(j=n-1;j>i;j--)
			if(R[j]<R[j-1])
			{
				temp=R[j];
				R[j]=R[j-1];
				R[j-1]=temp;
				flag=1;
			}
		if(flag==0)
			return;
	}
}

int main()
{
	int i;
	int R[9]={6,54,3,90,33,7,1,99,44};
	BulleSort(R,9);
	for(i=0;i<9;i++)
		printf("%d  ",R[i]);
	return 0;
}
