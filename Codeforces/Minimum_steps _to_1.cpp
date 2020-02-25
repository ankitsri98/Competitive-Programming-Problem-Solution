#include <bits/stdc++.h>
using namespace std;

int fun2(int x,int* dp){
    
    if(x==1){
        return 0;
    }
    if(dp[x]>-1){
        return dp[x];
    }
    int a=INT_MAX,b=INT_MAX,c=INT_MAX;//in iterative method store prevalues of 0 1 2 3
    if(x%3==0){
    a=fun2(x/3,dp)+1;
    }
    if(x%2==0){
    b=fun2(x/2,dp)+1;
    }
    c=fun2(x-1,dp)+1;
    int ans=min(min(a,b),c);
    //cout<<ans<<endl;
    dp[x]=ans;
    return ans;
}
int main() {
    int* dp=new int[100005];
    for(int i=0;i<100005;i++){
        dp[i]=-1;
    }
    cout<<fun2(21,dp)<<endl;
      /*  for(int i=0;i<50;i++){
        cout<<i<<"   "<<dp[i]<<endl;
    }*/
}
