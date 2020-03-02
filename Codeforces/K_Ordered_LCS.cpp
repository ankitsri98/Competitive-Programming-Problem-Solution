#include <bits/stdc++.h>
using namespace std;

int a1[2005],a2[2005];
int dp[2005][2005][8];
int k_ordered_lcs(int m,int n ,int k){
    if(m==0 || n==0){
        return 0;
    }
    if(dp[m][n][k]>-1){
        return dp[m][n][k];
    }
    if(a1[m-1]==a2[n-1]){
        dp[m][n][k]=1+k_ordered_lcs(m-1,n-1,k);
    }
    else{
        int a=0,b=0,c=0;
        if(k>0){
            a=1+k_ordered_lcs(m-1,n-1,k-1);
        }
        
            b=k_ordered_lcs(m-1,n,k);
            c=k_ordered_lcs(m,n-1,k);
        
        dp[m][n][k]=max(a,max(b,c));
    }
    return dp[m][n][k];
}

int main() {
    int n,k,m;
    cin>>m>>n>>k;
    for(int i=0;i<m;i++){
        cin>>a1[i];
    }
    for(int i=0;i<n;i++){
        cin>>a2[i];
    }
    /*for(int i=0;i<=m;i++){
        for(int j=0;j<=n;j++){
            for(int k=0;k<8;k++){
                dp[i][j][k]=-1;
            }
        }
    }*/
    memset(dp,-1,sizeof(dp));
    cout<<k_ordered_lcs(m,n,k)<<endl;
}
