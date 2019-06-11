#include <stdio.h>

void InsertSort (int R[],int n)
{
	int i,j,temp;
	for(i=1;i<n;i++)
	{
		temp=R[i];
		j=i-1;
		while(j>=0&&temp<R[j])
		{
			R[j+1]=R[j];
			--j;
		}//while
		R[j+1]=temp;
	}//for
}

int main()
{
	int i;
	int R[6]={6,54,3,90,33,7};
	InsertSort(R,6);
	for(i=0;i<6;i++)
		printf("%d  ",R[i]);
	return 0;
}
