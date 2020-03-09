#include <bits/stdc++.h>
using namespace std;

int max_profit(int* arr,int* dp,int n){
    if(n==0){
        return 0;
    }
    if(dp[n]>-1){
        return dp[n];
    }
    //cout<<"n par call "<<n<<endl;
    int best=0;
    for(int i=1;i<=n;i++){
        int pro=arr[i]+max_profit(arr,dp,n-i);
        best=max(best,pro);
        //cout<<"i : "<<i<<" pro: "<<pro<<" best : "<<best<<endl;
    }
    dp[n]=best;
    //cout<<"loop for "<<n<<"  ends "<<endl;
    return best;
    
}

int iterative(int* arr,int n){
    int dp1[n+1]={0};
    dp1[1]=arr[1];
    for(int i=2;i<=n;i++){
        int best=0;
        for(int j=1;j<=i;j++){

            int pro=arr[j]+dp1[i-j];
            best=max(best,pro);
        }
        dp1[i]=best;
    }
   /* for(int i=0;i<=n;i++){
        cout<<dp1[i]<<" ";
    }*/
    return dp1[n];
}
int main() {
   int n;
   cin>>n;
   int* dp=new int[n+1];
   int* arr=new int[n+1];
   for(int i=0;i<=n;i++){
       dp[i]=-1;
   }
   for(int i=1;i<=n;i++){
       cin>>arr[i];
   }
   cout<<max_profit(arr,dp,n)<<endl;
   cout<<iterative(arr,n)<<endl;
}
