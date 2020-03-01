#include <bits/stdc++.h>
using namespace std;
const int N=1000005;
/*bool subset_sum(int* arr,int i,int n,int s){
    if(i==n){
        return 0;
    }
    bool a=subset_sum(arr,i+1,n,s);
    if(s>=arr[i-1]){
        bool b=subset_sum(arr,i+1,n,s-arr[i]);
    }
    bool c=a|b;
    return c;
    
}*/
//recursive top down DP
int  subset_sum1(int* arr,int n,int s,int** dp){
    if(s==0){
        return 1;
    }
    if(n==0 && s!=0){
        return 0;
    }
    if(dp[n][s]>-1){
        return dp[n][s];
    }
    int  a=subset_sum1(arr,n-1,s,dp);
    if(s>=arr[n-1]){
        a=a||subset_sum1(arr,n-1,s-arr[n-1],dp);
    }
    dp[n][s]=a;
    return dp[n][s];
}
//iterative dp
int subset_sum_iterative(int* arr,int n,int s,int** dp){
    
    for(int i=1;i<=s;i++){
        dp[0][i]=0;
    }
    for(int i=0;i<=n;i++){
        dp[i][0]=1;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=s;j++){
            dp[i][j]=dp[i-1][j];
            if(j>=arr[i-1]){
                dp[i][j]=dp[i][j]|| dp[i-1][j-arr[i-1]]; //arr[i-1] jo ki array element hai usko j sum se subtract kardo
            }
        }
    }
    for(int i=0;i<=n;i++){
        for(int j=0;j<=s;j++){
        cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
    return dp[n][s];
}
int main() {
    int n,s;cin>>n>>s;
    int* arr=new int[n+1];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int** dp=new int*[n+2];
    for(int i=0;i<=n+1;i++){
        dp[i]=new int[s+2];
    }
    for(int i=0;i<=n+1;i++){
        for(int j=0;j<=s+1;j++){
        dp[i][j]=-1;
        }
    }
    if(subset_sum_iterative(arr,n,s,dp)){
        cout<<"YES"<<endl;
    }
    else{
        cout<<"NO"<<endl;
    }
    
}
