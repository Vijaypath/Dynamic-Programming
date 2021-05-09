#include<bits/stdc++.h>
using namespace std;
int minstep(int n)
{
	int op1,op2,op3;
	op1=op2=op3=INT_MAX;
	if(n==1){
	  //Base case
	return 0;
}
//recurrsive case
op1=minstep(n-1);
if(n%2==0)
{
	op2=minstep(n/2);
}
if(n%3==0)
{
	op3=minstep(n/3);
}
return min(op1, min(op2,op3))+1;
}
int topdown(int n,int *dp)
{
	int op1,op2,op3;
	op1=op2=op3=INT_MAX;
	if(n==1){
	  //Base case
	return dp[n]=0;
}
if(dp[n]!=-1)
{
	return dp[n];
}
//recurrsive case
op1=topdown(n-1,dp);
if(n%2==0)
{
	op2=topdown(n/2,dp);
}
if(n%3==0)
{
	op3=topdown(n/3,dp);
}
return min(op1, min(op2,op3))+1;
}

int BtoUp(int n)
{
	int dp[1000];
		 dp[1]=0;
	 for(int i=2;i<=n;i++)
	 {
	 	int op1,op2,op3;
	    op1=op2=op3=INT_MAX;

op1=dp[i-1];
if(i%2==0)
{
	op2=dp[i/2];
}
if(i%3==0)
{
	op3=dp[i/3];
}
dp[i]= min(op1, min(op2,op3))+1;
}
for(int i=1;i<=n;i++)
{
	cout<<dp[i]<<" ";
}
cout<<endl;
return dp[n];
}

int main()
{
	int n;
	cin>>n;
	int *dp=new int[n+1];
	for(int i=0;i<=n;i++)
	{
		dp[i]=-1;
	}
	cout<<minstep(n)<<endl;
	cout<<topdown(n,dp)<<endl;
	cout<<BtoUp(n);

	return 0;
}
