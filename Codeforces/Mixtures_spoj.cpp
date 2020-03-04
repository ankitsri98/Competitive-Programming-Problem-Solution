#include <bits/stdc++.h>
using namespace std;

int a[1000];
long long int dp[1000][1000];
long long int sum(int i,int j){
    long long int s=0;
    for(int k=i;k<=j;k++){
        s+=a[k];
        s=s%100;
    }
    return s;
}
long long int solve_mixtures(int i,int j){
    if(i>=j){
        return 0;
    }
    if(dp[i][j]!=-1){
        return dp[i][j];
    }
    //we break our ans at every possible k
    dp[i][j]=INT_MAX;
    for(int k=i;k<=j;k++){
        dp[i][j]=min(dp[i][j],solve_mixtures(i,k)+solve_mixtures(k+1,j)+sum(i,k)*sum(k+1,j));
    }
    return dp[i][j];
}
int main() {
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    //memset(dp,-1,sizeof(dp));
    for(int i=0;i<=n;i++){
        for(int j=0;j<=n;j++){
            dp[i][j]=-1;
        }
    }
    cout<<solve_mixtures(0,n-1)<<endl;
}
