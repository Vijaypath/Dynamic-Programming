#include<bits/stdc++.h>
using namespace std;
//int memo[102][103];
//memset(memo, -1, sizeof(memo))
int zerooneknap(int wt[], int val[], int w, int n)
{
		if(n==0 || w==0)
	   return 0;       
       /* for (int i = 0; i < n; i++)
        for (int j = 0; j < w + 1; j++)
            dp[i][j] = -1;
        	   
	if(dp[n][w]!=-1)
	
	    return dp[n][w];
	  */
	  if(w>=wt[n-1])
	  {
	  	return max(val[n-1]+zerooneknap(wt,val,w-wt[n-1],n-1),zerooneknap(wt,val,w,n-1));
	  }
	  
	  else if(w<wt[n-1])
	  {
	  	return  zerooneknap(wt,val,w,n-1);
	  }
	 
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
