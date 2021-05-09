#include<bits/stdc++.h>
using namespace std;
unsigned nthuglinum(unsigned n)
{
    unsigned a[n];
	unsigned i=0;
	unsigned i2=0, i3=0, i5=0;

	unsigned nm2=2;
	unsigned nm3=3;
	unsigned nm5=5;
	unsigned nextunum=1;
	a[0]=1;
	for(int i=1;i<n;i++)
	{
	 nextunum=min(nm2, min(nm3,nm5));
	a[i]=nextunum;
	if(nextunum==nm2)
	{
		i2=i2+1;
		nm2=a[i2]*2;
	}
	if(nextunum==nm3)
	{
		i3=i3+1;
		nm3=a[i3]*3;
	}
	if(nextunum==nm5)
	{
		i5=i5+1;
		nm5=a[i5]*5;
	}
}
return nextunum;

}
int main()
{
   int n=4132;
	cout<<nthuglinum(n);
}
