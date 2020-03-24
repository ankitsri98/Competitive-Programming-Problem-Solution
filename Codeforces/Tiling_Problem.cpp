#include<bits/stdc++.h>
using namespace std;
#define ll long long int 
#define mod 1000000007
ll dp[100005];
int ways(ll n, ll m){
	if(n<m){
		return 1;
	}
	if(n==m){
		return 2;
	}
	if(dp[n]!=-1){
		return dp[n];
	}
	ll ans=0;
	if(n>m){
		ans=(ways(n-1,m)%mod+ways(n-m,m)%mod)%mod;
	}
	return dp[n]=ans;
}
int main() {
	ll t,n,m,x,z;
	cin>>t;
	while(t--){
		cin>>n>>m;
		memset(dp,-1,sizeof(dp));
		cout<<ways(n,m)<<endl;
	}
	return 0;
}