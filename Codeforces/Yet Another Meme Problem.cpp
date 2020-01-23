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
	   ll n,m,x,z,j,k,p,l,r; 
	   cin>>n>>m;
	   p=0;m+=1;
	   while(m>0)
	   {
	       p++;
	       m=m/10;
	   }
	   cout<<n*((p)-1)<<endl;
	   
	}
	return 0;
}