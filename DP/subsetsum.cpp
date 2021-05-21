#include<bits/stdc++.h>
using namespace std;
bool subsetsum(int item[], int n,int sum)
{
	if(sum==0)
	return true;
	if(n==0)
	return false;
	
	if(item[n-1]>sum)
	
	return subsetsum(item, n-1, sum);
	
	
	return subsetsum(item,n-1,sum) || subsetsum(item,n-1,sum-item[n-1]);
}

int main()
{
	int n,sum,item[1000];
	cin>>n;
	for(int i=0; i<n; i++)
	{
		cin>>item[i];
	}
	cin>>sum;
 if (subsetsum(item, n, sum) == true)
 cout<<"Found subset";
 else
 cout<<"not found";
}
