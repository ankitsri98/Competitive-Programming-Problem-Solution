#include <bits/stdc++.h>
using namespace std;
int lcs(int x, int y, string s1, string s2){
    
    int dp[x+2][y+2];
    for(int i=0;i<=x;i++){
        dp[i][0]=0;
    }
    for(int i=0;i<=y;i++){
        dp[0][i]=0;
    }
    int ans=0;
    for(int i=1;i<=x;i++){
        for(int j=1;j<=y;j++){
            if(s1[i-1]==s2[j-1]){
                dp[i][j]=dp[i-1][j-1]+1;
                ans=max(ans,dp[i][j]);
            }
            else{
                dp[i][j]=0;
            }
        }
    }
    /*for(int i=0;i<=x;i++){
        for(int j=0;j<=y;j++){
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }*/
    return ans;
}
int main() {
	int  n,t,m;
	cin>>t;
	while(t--){
	    cin>>n>>m;
	    string s1,s2;
	    cin>>s1>>s2;
	    cout<<lcs(s1.size(),s2.size(),s1,s2)<<endl;
	}
	return 0;
}