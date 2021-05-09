#include<bits/stdc++.h>
using namespace std;
int cntdearng(int n)
{
	if(n==1)
	{
		return 0;
	}
	if(n==2)
	{
		return 1;
	}
	return (n-1) * (cntdearng(n-1)+cntdearng(n-2));
}
int TopD(int n, int *dp)
{
	if(n==1)
	{
		return 0;
	}
	if(n==2)
	{
		return 1;
	}
	if(dp[n]!=-1)
	{
		return dp[n];
	}
	return (n-1) * (TopD(n-1,dp)+TopD(n-2,dp));
}

int BToup(int n)  //Linear space linear tome
{
 int *dp=new int[n+1];
  dp[1]=0;
  dp[2]=1;
	for(int i=3;i<=n;i++)
		dp[i]=(i-1) * (dp[i-1]+dp[i-2]);
	
	return dp[n];
}

int BToupspace(int n)  //Const space linear time
{
 //int *dp=new int[n+1];
  //dp[1]=0;
  //dp[2]=1;
  
  
  int b=1;
  int a=0;
	for(int i=3;i<=n;i++)
	{
	
	    int c=(i-1) * (b+a);
	    a=b;
	    b=c;
	}
	return b;
}


int main()
{
	int n;
	cin>>n;
	int *dp=new int[n+1];
	for(int i=0;i<n;i++)
	{
		dp[i]=-1;
	}
	cout<<BToupspace(n)<<endl; 
	cout<<BToup(n)<<endl;

	cout<<TopD(n,dp)<<endl;
	cout<<cntdearng(n)<<" ";
}
