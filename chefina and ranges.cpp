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
	   vector<pair<int,int> > a,b;
	   cin>>n;
	   for(int i=0;i<n;i++)
	   {
	       cin>>l>>r;
	       a.push_back(make_pair(l,0));
	       a.push_back(make_pair(r,1));
	   }
	   sort(a.begin(),a.end());
	   p=0;
	   for(int i=0;i<a.size();i++)
	   {
	       //cout<<a[i].first<<" "<<a[i].second<<endl;
	       if(a[i].second==0)
	       {
	           b.push_back(make_pair(++p,0));
	       }
	       else
	       {
	           b.push_back(make_pair(--p,1));
	       }
	   }
	   bool flag=false;
	   int count=1000000;
	   for(int i=0;i<b.size();i++)
	   {
	       //cout<<b[i].first<<" "<<b[i].second<<" "<<flag<<endl;
	       if(b[i].second==0 )
	       {
	           if(flag==true)
	           count=min(count,b[i].first-1);
	       }
	       else
	       {
	           flag=true;
	       }
	   }
	   if(count==1000000)
	   cout<<-1<<endl;
	   else
	   cout<<count<<endl;
	}
	return 0;
}
