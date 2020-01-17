#include <bits/stdc++.h>
using namespace std;
#define ll long long int 
int main() {
	
	ll x,z,y,n,m,ans,s,e,ss,sum;
	ll t;
	cin>>t;
	while(t--)
	{
		x=0;m=s=e=ss=0;
		cin>>n;
		ll a[n+1];
		for(int i=0;i<n;i++)
		{
			cin>>a[i];
			x+=a[i];
			if(a[i]>0)
			{
				m++;
			}
		}
		y=0;
		z=0;
		for(int i=0;i<n;i++)//range calculation
		{
			y+=a[i];
			
			if(y<0)
			{
				y=0;ss=i+1;
			}
			if(y>=z)
			{
				z=y;e=i;s=ss;
			}
		}
		//cout<<s<<" "<<e<<endl;
		if(m==(n))
		cout<<"YES"<<endl;
		else
		{
			//cout<<x<<" "<<z<<endl;
    		if(s==0 && e==n-1)
    		{
    			y=z=0;
    			for(int i=0;i<n-1;i++)
    			{
    				y+=a[i];
    				if(y<0)
    				{
    					y=0;
    				}
    				if(y>=z)
    				{
    					z=y;
    				}
    			}
    			sum=z;
    			y=z=0;
    			for(int i=1;i<n;i++)
    			{
    				y+=a[i];
    				if(y<0)
    				{
    					y=0;
    				}
    				if(y>=z)
    				{
    					z=y;
    				}
    			}
    			//cout<<"new sums"<<z<<" "<<sum<<endl;
    		}
    		z=max(z,sum);
    		if(x>z)
    		cout<<"YES"<<endl;
    		else
    		cout<<"NO"<<endl;
		}
	}
}