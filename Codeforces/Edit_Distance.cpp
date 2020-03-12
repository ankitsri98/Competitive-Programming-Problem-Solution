#include <bits/stdc++.h>
using namespace std;
const int N=1005;
int edit_distance(string s1,string s2,int m,int n,int dp[][N]){
    if(m==0 ){
        return n;
    }
    if(n==0){
    	return m;
    }
    if(dp[m][n]!=-1){
        return dp[m][n];
    }
    if(s1[m]==s2[n]){
        dp[m][n]=edit_distance(s1,s2,m-1,n-1,dp);
    }
    else if(s1[m]!=s2[n]){
        int a=1+edit_distance(s1,s2,m-1,n,dp);//replacement
        int b=1+edit_distance(s1,s2,m,n-1,dp);//deletion
        int c=1+edit_distance(s1,s2,m-1,n-1,dp);//insertion
        dp[m][n]=min(a,min(b,c));
    }
    return dp[m][n];
}


int edit_distance_iterative(string s1,string s2,int m,int n,int dp[][N]){

    for(int i=0;i<=m;i++){
        dp[i][0]=i;
    }
    for(int i=0;i<=n;i++){
        dp[0][n]=i;
    }
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            if(s1[i]==s2[j]){
                dp[i][j]=dp[i-1][j-1];
            }
            else{
                int a=dp[i-1][j-1]+1;
                int b=dp[i-1][j]+1;
                int c=dp[i][j-1]+1;
                dp[i][j]=min(a,min(b,c));
            }
        }
    }
    return dp[m][n];
}
int main() {
    string s1,s2;
    cin>>s1>>s2;
    int m,n;
    s1=" "+s1;
    s2=" "+s2;
    m=s1.length();
    n=s2.length();
    //cout<<m<<" "<<n<<endl;
    int dp[N][N];
    for(int i=0;i<=m;i++){
        for(int j=0;j<=n;j++){
            dp[i][j]=-1;
        }
    }
    cout<<edit_distance(s1,s2,m,n,dp)<<endl;
    cout<<edit_distance_iterative(s1,s2,m,n,dp)<<endl;
}
