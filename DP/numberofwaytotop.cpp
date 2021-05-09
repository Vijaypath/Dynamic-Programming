#include<bits/stdc++.h>
using namespace std;
int noofwaytotop(int n, int k)
{
	if (n==0)
	{
		return 1;
	}
	int ways=0;
	for(int i=1;i<=k;i++)
	{
		if(n-i>=0)// exclude the negative value
		{
		
		ways+=noofwaytotop(n-i, k);
	}
}
	return ways;
}
int noofwaytotopdown(int n, int k,int *dp)
{
	if (n==0)
	{
		return 1;
	}
	if(dp[n]!=-1)
	{
		return dp[n];
	}
	int ways=0;
	for(int i=1;i<=k;i++)
	{
		if(n-i>=0)// exclude the negative value
		{
		
		ways+=noofwaytotopdown(n-i, k,dp);
	}
}
	return dp[n]=ways;
}

int main()
{
	int n,k;
	cin>>n>>k;
	int *dp=new int[n+1];
	for(int i=0;i<=n;i++)
	{
		dp[i]=-1;
	}
	cout<<noofwaytotopdown(n,k,dp)<<endl;

	cout<<noofwaytotop(n,k)<<" ";
}
