#include <bits/stdc++.h>
using namespace std;
int dp[1005][1005];
int matrix_chain(int arr[],int i,int j){
    if(i>=j){
        dp[i][j]=0;
        return 0;
    }
    if(dp[i][j]!=-1){
        return dp[i][j];
    }
    int ans=INT_MAX;
    for(int k=i;k<j;k++){
        ans=min(ans,matrix_chain(arr,i,k)+matrix_chain(arr,k+1,j)+arr[i-1]*arr[k]*arr[j]);
    }
    return dp[i][j]=ans;
}
int matrix_chain_iter(int arr[],int n){
    dp[1005][1005]={0};
    for(int i=0;i<n;i++){
        dp[i][i]=0;
    }
    for(int L=2;L<n;L++){//calculating lengthwise ans
        for(int i=1;i<=n-L;i++){
            int j= i+ (L-1);
            dp[i][j]=INT_MAX;
            for(int k=i;k<j;k++){
                dp[i][j]=min(dp[i][j],dp[i][k]+dp[k+1][j]+arr[i-1]*arr[k]*arr[j]);
            }
        }
    }
    return dp[1][n-1];
}
int main() {
    int matrices[]={1,2,3,4};
    memset(dp,-1,sizeof(dp));
    cout<<matrix_chain(matrices,1,3)<<endl;
    //PRintng dp array
    cout<<matrix_chain_iter(matrices,4)<<endl;
    for(int i=1;i<4;i++){
        for(int j=1;j<4;j++){
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
}
