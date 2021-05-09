#include<bits/stdc++.h>
using namespace std;
int maxdivide(int a, int b)
{
	while(a%b==0)
		a=a/b;
		return a;
}
	int isugli(int no)
	{
	 no=maxdivide(no,2);
	 no=maxdivide(no,3);
	 no=maxdivide(no,5);
	return (no==1) ?1 :0;
	}
	int getnthugly(int n)
	{
		int i=1;
		int cnt=1;
		while(n>cnt)
		{
		    i++;
			if(isugli(i))
			cnt++;
		}
		return i;
	}
	int main()
	{
		unsigned no=getnthugly(8);
		cout<<no;
		getchar(); 
	    return 0; 
	}
