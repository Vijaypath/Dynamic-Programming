#include<bits/stdc++.h>
using namespace std;
int LCS(string & s1 , string& s2,int i, int j)
{
	if(i==s1.length() or j==s2.length())
	{
		return 0;
	}
	if(s1[i]==s2[j])
	return 1+LCS(s1,s2,i+1,j+1);
	return max(LCS(s1,s2,i+1,j),LCS(s1,s2,i,j+1));
}

int LCSTopD(string& s1 , string& s2, int i, int j,vector<vector<int>>& memo)
{
	if(i==s1.length() or j==s2.length())
	{
		return 0;
	}
	if(memo[i][j]!=-1)
	{
		return memo[i][j];
	}
	if(s1[i]==s2[j])
	return memo[i][j]=1+LCSTopD(s1,s2,i+1,j+1,memo);
	return memo[i][j]= max(LCSTopD(s1,s2,i+1,j,memo),LCSTopD(s1,s2,i,j+1,memo));
}

int main()
{
	string s1;
	cin>>s1;
	string s2;
	cin>>s2;
	cout<<LCS(s1,s2,0,0)<<endl;
	vector<vector<int>> memo(s1.length(), vector<int>(s2.length(),-1));
	cout<<LCSTopD(s1,s2,0,0,memo)<<endl;

}
