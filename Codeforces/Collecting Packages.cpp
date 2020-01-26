#include <bits/stdc++.h>
using namespace std;
#define ll long long int

struct code{
    
    ll x;ll y;
};

bool compare(code a,code b)
{
    if(a.y!=b.y)
    {
        return a.y<b.y ;
    }
    else
    {
        return a.x<b.x;
    }
}
int main() {
	
	ll n,m,i,j,p,q,k,z,s,a,b;
	cin>>s;
	while(s--)
	{
	    cin>>n;
	    code arr[n+1];
	    for(i=0;i<n;i++)
	    {
	        cin>>arr[i].x>>arr[i].y;
	    }
	    sort(arr,arr+n,compare);
	    string st;
	    k=0;
	    a=b=0;
	    for(i=0;i<n;i++)
	    {
	        p=arr[i].x-a; q=arr[i].y-b;
	        if(p<0 || q<0){
	        cout<<"NO"<<endl;
	        k=1;
	        break;
	            
	        }
	        while(p!=0)
	        {
                st+="R";p--;	            
	        }
	        while(q!=0)
	        {
	            st+="U";q--;
	        }
	        a=arr[i].x; b=arr[i].y;
	    }
	    if(k==0)
	    {
	        cout<<"YES"<<endl;
	        cout<<st<<endl;
	    }
	    
	}
	return 0;
}
