#include<bits/stdc++.h>
using namespace std;
bool subset(int item[], int n, int sum) // we have to make this function is bool because we have
                                        // to return true or false from the table
{
	bool set[n+1][sum+1];  // 2D array for fill the table 
	
	for(int i=0; i<=n; i++) // initlizatuon of the tavles values
	
	 set[i][0]=true;
	 
	for(int i=1; i<=sum; i++)
	
	  set[0][i]=false;
	  
	  for(int i=1; i<=n; i++) // these two loops for fill the remaning values in the table
	  
	  for(int j=1; j<=sum; j++)
	  
	  if(item[i]>j)  // this condition is checking for where the given sum is less 
	                //than the each element in the arrays
	  
	  set[i][j]=set[i-1][j]; // is so then assign the values in tables
	  
	  else if(item[i]<=j)  // this is for sum is greter the each element persent in the arrays
	  
	  set[i][j]=set[i-1][j] || set[i-1][j-item[i-1]];  // then accordingly we have to take a decisions 
	  
	  return set[n][sum];  // and at last we have to return the last index of sum and size
	                      // of the table values.
}
// this is our main 

int main()
{
	int n, sum, item[100];
	cin>>n;
	for(int i=0; i<n; i++)
	{
		cin>>item[i];
	}
	cin>>sum;
	if(subset(item,n,sum)==true)
	cout<<"found the subset";
	else
	cout<<"do not found subset";
}
