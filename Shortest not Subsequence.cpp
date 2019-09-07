#include<bits/stdc++.h>
using namespace std;
int f(string s,int i,int n,string v ,int j,int m,int** dp)
{
    if(i==n)
        return 1005;
    if(j>=m)
        return 1;
    if(dp[i][j]!=-1)
        return dp[i][j];
    int ans=f(s,i+1,n,v,j,m,dp);//excluding
    char ch=s[i];
    int ans1,k,x;
    for( k=j;k<m;k++)
    {
        if(v[k]==ch)
        {
            break;
        }
    }
    if(k==m)
        return 1;
    // cout<<"n: "<<n<<endl;
    // cout<<"ans: "<<ans<<endl;
    ans1=f(s,i+1,n,v,k+1,m,dp)+1;//INCLUDING
    // cout<<"ans1: "<<ans1<<endl;
    dp[i][j]= min(ans1,ans);
    
    // for(int i=0;i<=n;i++)
    // {
    //     for(int j=0;j<=m;j++)
    //     {
    //         cout<<dp[i][j]<<"   ";
    //     }
    //     cout<<endl;
    // }
    
    return dp[i][j];
}
int solve(string S,string V)
{
    int** dp=new int*[S.length()+1];
    for(int i=0;i<=S.length();i++)
    {
        dp[i]=new int[V.length()+1];
    }
    for(int i=0;i<=S.length();i++)
    {
        for(int j=0;j<=V.length();j++)
        {
            dp[i][j]=-1;
        }
    }
	return f(S,0,S.length(),V,0,V.length(),dp);

}
/*int solvee(string S,string V,int **dp){
    if(S.empty()){
        return INT_MAX-1;
    }
    if(V.empty()){
        return 1;
    }
    if(dp[S.size()][V.size()]>-1){
        return dp[S.size()][V.size()];
    }
    
    int option1 = solvee(S.substr(1),V,dp);
    int index=0;
    for(int i=0; i<=V.size(); i++){
        if(i==V.size()){
            return 1;
        }
        if(S[0]==V[i]){
            index=i;
            break;
        }
    }
    
    int option2 = 1+solvee(S.substr(1),V.substr(index+1),dp);

    
    dp[S.size()][V.size()] =  min(option1,option2);
    return dp[S.size()][V.size()];
    
}
int solve(string S,string V)
{
int **dp = new int*[S.size()+1];
    for(int i=0; i<S.size()+1; i++){
        dp[i] = new int[V.size()+1];
        for(int j=0; j<V.size()+1; j++){
            dp[i][j]=-1;
        }
    }
    
    int ans = solvee(S,V,dp);
    return ans;
}

*/