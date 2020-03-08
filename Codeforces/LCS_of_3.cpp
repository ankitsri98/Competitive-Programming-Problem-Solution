#include <bits/stdc++.h>

using namespace std;

int dp[201][201][201];
string s1,s2,s3;
int lcs(int n,int m ,int k)
{
	if(n<0||m<0||k<0)
        return 0;

    if(dp[n][m][k] !=-1)
        return dp[n][m][k];
	
	if(n==0||m==0||k==0)//this condition is put as if index is zeo then in next step it will search for n-1 and m-1 condition which is invalid 
    {
		dp[n][m][k] = 0;
		return dp[n][m][k];

	}    

    else if(s1[n-1]==s2[m-1] && s2[m-1]==s3[k-1])
	{
        dp[n][m][k] = 1+lcs(n-1,m-1,k-1);
		return dp[n][m][k];
    }
    else{
        dp[n][m][k]=max(lcs(n-1,m,k),max(lcs(n,m-1,k),lcs(n,m,k-1)));
		return dp[n][m][k];
    }
}
int main() {
	memset(dp,-1,sizeof(dp));
    cin>>s1>>s2>>s3;
    int x=s1.size(),y=s2.size(),z=s3.size();
    cout<<lcs(x,y,z)<<endl;
}
