#include<iostream>
using namespace std;
int fibo(int n, int *dp)
{
    if(n==0 || n==1)
    {
    	return n;
	}
	if(dp[n]!=-1)    // if d[p] arrays is not -1 then return the dp[] 
	{
		return dp[n];
	}
	
	/*int ans=(fibo(n-1) + fibo(n-2));
	dp[n]=ans;  //before return  the ans need to be stored first then return 
	return ans;*/
	return dp[n]=fibo(n-1, dp) + fibo(n-2, dp);  // calculate using recuursive call
	
}
int bottomUp(int n)
{
	int dp[1000]={-1};
	
	dp[0]=0;
	dp[1]=1;
	for(int i=2;i<=n;i++)
	{
		dp[i]=dp[i-1]+ dp[i-2];
	}
	return dp[n];
}

int main()
{
	int n;
	cin>>n;
	int *dp=new int[n+1];    //dynamic  memory allocations 
	for(int i=0; i<=n; i++)  // initlize the dp[]with value  -1
	{
		dp[i]=-1;
	}
	
	cout<<fibo(n, dp)<<endl;
	cout<<bottomUp(n)<<endl;

	return 0;
}
