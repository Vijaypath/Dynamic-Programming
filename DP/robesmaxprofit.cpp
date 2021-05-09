#include<bits/stdc++.h>
using namespace std;
int maxprofit(int a[],int n,int i)
{
	if(i>=n)
	{
		return 0;
	}
	int x=maxprofit(a, n,i+2);
	int y=maxprofit(a, n, i+1);
	
	return max(a[i]+x,y);
}

int maxprofittopD(int a[],int n,int i,int * memo)
{
	if(i>=n)
	{
		return 0;
	}
	if(memo[i]!=-1)
	{
		return memo[i];
	}
	int x=maxprofittopD(a, n,i+2,memo);
	int y=maxprofittopD(a, n, i+1,memo);
	
	return memo[n]=max(a[i]+x,y);
}
int maxprofitBtoUp(int a[],int n)
{
	int *dp=new int[n+1];
	dp[n]=0;  // no house to rob
	dp[n-1]=a[n-1];  // only one house left the last house so ob it to maxmize profit
	for(int i=n-2;i>=0;i--)
		dp[i]=max(a[i]+dp[i+2],dp[i+1]);
	return dp[0];
	}
int main()
{
	int n;
	cin>>n;
	int a[100];
	for(int i=0;i<n;i++)
    {
    	cin>>a[i];
	}
	int *memo=new int[n+1];
	for(int i=0;i<=n;i++)
	{
		memo[i]=-1;
	}
	cout<<maxprofitBtoUp(a,n)<<endl;
	cout<<maxprofittopD(a,n,0,memo)<<endl;
	cout<<maxprofit(a,n,0);
}
