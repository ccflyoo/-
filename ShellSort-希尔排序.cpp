#include <stdio.h>

void ShellSort(int R[],int n)
{
	int i,j,m,temp;
	int gap=n;
	do{
		gap=gap/3+1;
		for(i=0;i<gap;i++)
		{
			for(j=i+gap;j<n;j+=gap)
			{
				if(R[j]<R[j-gap])
				{
					temp=R[j];
					m=j-gap;
					while(m>=0&&R[m]>temp)
					{ 
						R[m+gap]=R[m];
						m=m-gap;
					}
					R[m+gap]=temp;
				}
			}
		} 	
	}while(gap>1);
} 

int main()
{
	int i;
	int R[9]={6,54,3,90,33,7,1,99,44};
	ShellSort(R,9);
	for(i=0;i<9;i++)
		printf("%d  ",R[i]);
	return 0;
}
