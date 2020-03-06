#include <bits/stdc++.h>
using namespace std;

int dp[1005][1005];
int knapsack(int* arr,int* val,int n,int s){
    if(n==0||s<=0)
    return 0;
    if(dp[n][s]>-1){
        return dp[n][s];
    }
    int a=-1,b=-1;
    if(s>=arr[n-1]){
        a=val[n-1]+knapsack(arr,val,n-1,s-arr[n-1]);
    }
    b=knapsack(arr,val,n-1,s);
    return dp[n][s]=max(a,b);

}
int iterative(int* arr,int* val,int n,int s){
    
    for(int i=0;i<=n;i++){
        dp[i][0]=0;
    }
    for(int i=0;i<=s;i++){
        dp[0][i]=0;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=s;j++){
            dp[i][j]=dp[i-1][j];
            if(s>=arr[i-1]){
                dp[i][j]=max(dp[i][j],dp[i-1][j-arr[i-1]]+val[i-1]);
            }
        }
    }
    return dp[n][s];
}
int main() {
    int n,s;
    //memset(dp,-1,sizeof(dp));
    cin>>n>>s;
    int* arr=new int[n+1];
    int* val=new int[n+1];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    for(int i=0;i<n;i++){
        cin>>val[i];
    }
    //cout<<knapsack(arr,val,n,s)<<endl;
    cout<<iterative(arr,val,n,s)<<endl;
}
