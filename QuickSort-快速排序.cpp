#include <stdio.h>

void QuickSort(int R[],int low,int high)
{
	int i=low,j=high;
	int temp;
	if(low<high)								//最终low=high 
	{
		temp=R[low];
		while(i<j)								//每一趟i=j 
		{
			while(i<j&&R[j]>=temp)	j--;		//找出小于的值 
			if(i<j)	
			{
				R[i]=R[j];
				i++;
			}
			while(i<j&&R[i]<temp)	i++;		//找出大于的值 
			if(i<j)
			{
				R[j]=R[i];
				j--;
			}
			
		}//while
		R[i]=temp;								//最后安置temp 
		QuickSort(R,low,i-1);
		QuickSort(R,i+1,high);
	}//if
}

int main()
{
	int i;
	int R[9]={6,54,3,90,33,7,1,99,44};
	QuickSort(R,0,8);
	for(i=0;i<9;i++)
		printf("%d  ",R[i]);
	return 0;
}
