#include <bits/stdc++.h>
using namespace std;
int a[102][102];
int dp[102][102]={0};

//TRIED BOTTOM UP APPROACH
int fun1(int i,int k,int n,int m)
{
    int ans=0;
    for(int i=1;i<=m;i++)//for FIRST ROW THE ANSWER WILL BE FIRST ROW 
        dp[1][i]=a[1][i];
    
    for(int i=2;i<=n;i++)
    {
        for(int j=1;j<=m;j++)//MAIN LOGIC IS MIN OF DP OF LAST VALUE+ PRESENT VALUE OF ARRAY
        {
            if(j==m)
            {
                dp[i][j]+=min(dp[i-1][j],dp[i-1][j-1])+a[i][j];
            }
            else if(j==1)
            {
                dp[i][j]+=min(dp[i-1][j],dp[i-1][j+1])+a[i][j];
            }
            else
            {
                dp[i][j]+=min(dp[i-1][j-1],min(dp[i-1][j],dp[i-1][j+1]))+a[i][j]; 
            }
        }
    }
  /*  for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            cout<<dp[i][j]<<"   ";
        }
        cout<<endl;
    }*/
     int x=INT_MAX;
    for(int i=1;i<=m;i++)//SO AS IT IS TOP DOWN APPROACH MIN IN LAST ROW IS THE ANSWER
    {
        if(dp[n][i]<x)
            x=dp[n][i];
    }
    return x;
}
int main()
{
    int n,m,i,j,k,l,x,z;
    cin>>n>>m;
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=m;j++)
        {
            cin>>a[i][j];
        }
    }

    cout<<fun1(1,1,n,m)<<endl;
    return 0;
}
