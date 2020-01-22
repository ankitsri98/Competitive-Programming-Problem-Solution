#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define ll long long int
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	   ll n,m,k,j,a,b,c;
	   cin>>a>>b>>c>>n;
	   n+=a+b+c;
	   k=max(max(a,b),c);
	   if(n%3==0 && (n/3)>=k)
	   cout<<"YES"<<endl;
	   else
	   cout<<"NO"<<endl;
	   
	}
	return 0;
}
