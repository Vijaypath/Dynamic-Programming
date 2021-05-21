#include<bits/stdc++.h>
using namespace std;
bool issubsetsum(int arr[], int n, int sum)
{
	if(sum==0)
	return true;
	
	if(n==0 && sum!=0)
	return false;
	
	if(arr[n-1]>sum)
	return issubsetsum(arr, n-1, sum);
	
	else if(arr[n-1]<=sum)
	return issubsetsum(arr, n-1,sum) || issubsetsum(arr, n-1, sum-arr[n-1]);
	
}
bool equalsumparti(int arr[],int n)
{
	int sum=0, target;
	for(int i=0; i<n; i++)
	{
		sum+=arr[i];
	}
	if(sum==0)
	return true;
	
	if((sum%2)!=0)
	  return false;

	return issubsetsum(arr,n, sum/2);
	
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
	if(equalsumparti(arr,n)==true)
	  cout<<"partition is possible";
	
	else
	   cout<<"partition is not possible";
	
}
