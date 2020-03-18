#include <bits/stdc++.h>
using namespace std;

int lis(int* arr,int* dp,int n){
    for(int i=2;i<=n;i++){
        int best=1;//remember this case as minimum length is 1 having single element 
        for(int j=1;j<=i;j++){
            if(arr[i]>arr[j]){
                best=max(best,dp[j]+1);
            }
        }
        dp[i]=best;
    }
    int m=-1;
    for(int i=1;i<=n;i++){//every index stores length of LIS ending at that index so now traverse to fnd  maximum
        cout<<dp[i]<<" ";
        if(dp[i]>m){
            m=dp[i];
        }
    }
    return m;
}
int main() {
    int n;
    cin>>n;
    int* arr=new int[n+2];
    for(int i=1;i<=n;i++){
        cin>>arr[i];
    }
    int * dp=new int[n+2];
    for(int i=0;i<=n;i++){
        dp[i]=1;
    }
    cout<<lis(arr,dp,n)<<endl;
}
