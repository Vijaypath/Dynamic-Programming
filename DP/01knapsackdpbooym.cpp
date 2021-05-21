#include<bits/stdc++.h>
using namespace std;
//int memo[102][103];
//memset(memo, -1, sizeof(memo))
//in recurrsion the time complexity is Exponential and when we use dynamic then T.C is o(n2)

int zerooneknap(int wt[], int val[], int w, int n)
{
	//Base condit in recurrsion = initilization in Bottom up
	int dp[n+1][w+1];
	for(int i=0; i<n+1; i++)
	for(int j=0; j<w+1; j++)
	if(i==0 || j==0)
	
	   dp[i][j]=0;
	   
	   	for(int i=1; i<n+1; i++)
	     for(int j=1; j<w+1; j++)
	     
	     if(wt[i-1]<=j)
	     dp[i][j] = max(val[i-1]+ dp[i-1][j-wt[i-1]], dp[i-1][j]);
	     
	     else 
		 dp[i][j]=dp[i-1][j];
		 
		 return dp[n][w];
	}
	
	
	int main()
   {
	int n,w,wt[100],val[100];
	cin>>n;
	
	for(int i=0; i<n; i++)
	{
		cin>>wt[i];
	}
		for(int i=0; i<n; i++)
	{
		cin>>val[i];
	}
	cin>>w;
	/*int  **dp = new int*[n];
     for (int i = 0; i < n; i++)
        dp[i] = new int[w + 1];	
	*/
	cout<<zerooneknap(wt,val,w,n);
	
}
	
