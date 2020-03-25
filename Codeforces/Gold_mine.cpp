#include <bits/stdc++.h>
using namespace std;
int arr[1000][1000]={0};
int r,c;
int dp[1000][1000];
int max_gold(int i,int j){
    if(i<1||i>r||j>c){
        return 0;
    }
    if(dp[i][j]!=-1){
    	return dp[i][j];
    }
    int a=-1,b=-1,c=-1,ans=-1;
    a=arr[i][j]+max_gold(i-1,j+1);
    b=arr[i][j]+max_gold(i,j+1);
    c=arr[i][j]+max_gold(i+1,j+1);
    ans=max(a,max(b,c));
    return dp[i][j]=ans;

}
int main() {
    cin>>r>>c;
    for(int i=1;i<=r;i++){
        for(int j=1;j<=c;j++){
            cin>>arr[i][j];
        }
    } 
    	memset(dp,-1,sizeof(dp));
		int ans=-1;
        for(int i=1;i<=r;i++){
            ans=max(ans,max_gold(i,1));
        }
        cout<<ans<<endl;
}
