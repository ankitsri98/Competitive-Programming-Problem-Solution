#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,m,k,i,j,x=INT_MAX,z,s,q,l,r;
    cin>>n>>m;
    int a[n+2][m+2],dp[n+2][m+2]={0};
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=m;j++)
        {
            cin>>a[i][j];
            dp[1][j]=1;
        }
    }
    for(i=1;i<=m;i++)//SO IN DP ARRAY FOR EVERY DP[I][J] WE ARE TRYING TO STORE THE INDEX OF
    {//OF UPPER ROW FROM WHERE TILL J'TH INDEX THE VALUES IN COLUMN VERTICALLY ARE IN 
        //ASCENDING ORDER
        for(j=2;j<=n;j++)
        {
            if(a[j][i]>=a[j-1][i])
            {
                dp[j][i]+=dp[j-1][i];
            }
            else
            {
                dp[j][i]=j;
            }
        }
    }
    int row[n+2]={0};
   /* for(i=1;i<=n;i++)
    {
        for(j=1;j<=m;j++)
        {
            cout<<dp[i][j]<<"   "; 
        }
        cout<<endl;
    }*/
    for(i=1;i<=n;i++)//NOW WE KNOW THAT QUERIES WILL BE 2 ROWS INDEXES SO WE WILL
        //CLCULATE THE MIN OF EACH ROW AND STORE IN A PARTICULAR ARRAY
    {
        x=INT_MAX;
        for(j=1;j<=m;j++)
        {
             if(dp[i][j]<x)
                 x=dp[i][j];
        }
        row[i]=x;
    }
    /*for(i=1;i<=n;i++)
    {
        cout<<row[i]<<" ";
    }
    cout<<endl;*/
    cin>>q;
    while(q--)//NOW FOR EACH [L,R] WE WILL GO TO R'TH INDEX AND CHECK WHETHER L IS  GREATER 
        //THAN ROW[R] 
    {
        cin>>l>>r;
        if(l>=row[r])
            cout<<"Yes"<<endl;
        else
            cout<<"No"<<endl;
    }
    return 0;
}
