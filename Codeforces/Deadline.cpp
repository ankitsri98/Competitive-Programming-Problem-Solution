#include <bits/stdc++.h>
using namespace std;
#define ll long long int 
int main() {
	
	ll z,y,n,m,ans,s,e,ss,sum,d;
	ll t;
	cin>>t;
	while(t--)
	{
	    int flag=0;
	    cin>>n>>d;
	    float x=sqrt(d)-1.0;
	    y=ceil(x);z=floor(x);
	   // cout<<"asda"<<sum<<endl;
	        if( (z)+ceil(d/((z*1.0)+1))<=n || (y+ceil(d/(y*1.0)+1)) <=n)
	        {
	            flag=1;
	           
	        }
	    if(flag==1)
	    {
	        cout<<"YES"<<endl;
	    }
	    else
	    cout<<"NO"<<endl;
	}
	return 0;
}