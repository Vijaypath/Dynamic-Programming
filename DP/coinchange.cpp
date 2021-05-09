#include<bits/stdc++.h>
using namespace std;
int coinchange(int amt, int *demo, int n)
{
	
	//base case
	if(amt==0)
	{
		return 0;
	}
	// recurrsive case
	int ans=INT_MAX;
	for(int i=0;i<n;i++)
	{
		if(amt>=demo[i])
		{
			int sa=coinchange(amt-demo[i],demo,n);
			if(sa!=INT_MAX)
			{
				ans=min(sa+1, ans); 
			}
		}
	}
	return ans;
}

int TopD(int amt, int *demo, int n,int *dp)
{
	
	//base case
	if(amt==0)
	{
		return dp[amt]= 0;
	}
	if(dp[amt]!=-1)
	{
		return dp[amt];
	}
	// recurrsive case
	int ans=INT_MAX;
	for(int i=0;i<n;i++)
	{
		if(amt>=demo[i])
		{
			int sa=TopD(amt-demo[i],demo,n,dp);
			if(sa!=INT_MAX)
			{
				ans=min(sa+1, ans); 
			}
		}
	}
	return dp[amt]=ans;
}
int BtoUp(int amt, int *demo, int m)
{
	int * dp=new int[amt+1];
	for(int i=0;i<=amt;i++)
	{
		dp[i]=INT_MAX;
	}
	dp[0]=0;
	for(int rs=1; rs<=amt;rs++)
	{
		for(int i=0;i<m;i++)
		{
			if(rs>=demo[i])
			{
			
			dp[rs]=min(1+ dp[rs-demo[i]],dp[rs]);
		}
	}
}
	for(int i=0;i<=amt;i++)
	{
		cout<<dp[i]<<" ";
	}
	cout<<endl;
	return dp[amt];
}


int main()
{
	int demo[4]={1 ,2 ,5,10};
	int amt;
	cin>>amt;
	int *dp=new int[amt+1];
    for(int i=0;i<=amt;i++)
    {
    	dp[i]=-1;
	}
	cout<<BtoUp(amt,demo,4)<<endl;
	cout<<TopD(amt, demo,4,dp)<<endl;

	cout<<coinchange(amt, demo,4)<<endl;
	return 0;
}
