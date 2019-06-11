#include <stdio.h>

void MergeSort(int R[],int low,int high) 
{
	if(low<high)
	{
		int mid=(low+high)/2;
		MergeSort(R,low,mid);
		MergeSort(R,mid+1,high);
		Merge(R,low,mid,high); 
	}
}
