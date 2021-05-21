#include<bits/stdc++.h>
using namespace std;
bool isequalparti(int arr[],int n)
{
	int sum=0;
	for(int i=0; i<n; i++)
	sum+=arr[i];
	
	if(sum==0)
	  return true;
	
	if(sum%2!=0)
	  return false;
	  
	  int dp[n+1][sum/2+1];
	  for(int i=0; i<=n;i++)
	   dp[i][0]=true;
	   
	   for(int i=1; i<=sum/2; i++)
	     dp[0][i]=false;
	
	for(int i=1; i<=n; i++)
	for(int j=1; j<=sum/2; j++)
	
	if(j<arr[i])
	
	dp[i][j]=dp[i-1][j];
	
	else if(j>=arr[i])
	
	dp[i][j]=dp[i-1][j] || dp[i-1][j-arr[i-1]];
	
	return dp[n][sum/2];
}
	   
	   
int main()
{
	int n;
	cin>>n;
    int arr[n];

	for(int i=0; i<n; i++)
	{
		cin>>arr[i];
	}
	if(isequalparti(arr,n)==true)
	  cout<<"partition is possible";
	
	else
	   cout<<"partition is not possible";
	
}



