#include<iostream>
#include<stdio.h>
using namespace std;

/***��A�ƶ���B����C��������***/ 
void Hanoi_Tower(int n,char A,char B,char C)
{
	if(n==1)
		cout<<A<<"->"<<B<<endl;
	else
	{
		Hanoi_Tower(n-1,A,C,B);
		cout<<A<<"->"<<B<<endl;
		Hanoi_Tower(n-1,C,B,A);
	}
}

int main()
{
	int n;
	cout<<"������n:"<<endl;
	cin>>n; 
	Hanoi_Tower(n,'A','B','C');
	return 0; 

}
