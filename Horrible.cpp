#include<bits/stdc++.h>
using namespace std;
#define ll long long  

void update(ll tree[],ll lazy[],int idx,int s,int e,int l,int r,ll val)
{
    if(s>e)
        return;
    if(lazy[idx]!=0)
    {
        ll x =lazy[idx];
        tree[idx]+=(e-s+1)*x;
    
    	if(s!=e)
    	{
    	    lazy[2*idx]+=lazy[idx];
    	    lazy[2*idx+1]+=lazy[idx];
    	}
    	lazy[idx]=0;
    }
    if(s>r||e<l)
        return;
    if(s>=l && e<=r)
    {
        tree[idx]+=(e-s+1)*val;
        if(s!=e)
        {
            lazy[2*idx]+=val;
            lazy[2*idx+1]+=val;
        }
        return ;
    }
    int mid=(s+e)/2;
    update(tree,lazy,2*idx,s,mid,l,r,val);
    update(tree,lazy,2*idx+1,mid+1,e,l,r,val);
    tree[idx]=tree[2*idx]+tree[2*idx+1];
    return ;
}
ll query(ll tree[],ll lazy[],int idx,int s,int e,int l,int r)
{
    if(lazy[idx]!=0)
    {
        ll x =lazy[idx];
        tree[idx]+=(e-s+1)*x;
    
    	if(s!=e)
    	{
    	    lazy[2*idx]+=lazy[idx];
    	    lazy[2*idx+1]+=lazy[idx];
    	}
    	lazy[idx]=0;
    }
    if(s>e)
        return 0;
    if(lazy[idx]!=0)
    {
        ll x =lazy[idx];
        tree[idx]+=(e-s+1)*x;
    	if(s!=e)
    	{
    	        lazy[2*idx]+=lazy[idx];
    	        lazy[2*idx+1]+=lazy[idx];
    	}
        //return tree[idx];
    }	
    if(s>r || e<l)
        return 0;
    if(s>=l && e<=r)
    {
        return tree[idx];
    }
    int mid=(s+e)/2;
    ll i=query(tree,lazy,2*idx,s,mid,l,r);
    ll j=query(tree,lazy,2*idx+1,mid+1,e,l,r);
    return i+j;
}
int main() 
{
    int t,n,m,i,j,k,x,y;
    ll z;
    cin>>t;
    while(t--)
    {
        cin>>n>>m;
        int a[n]={0};
        ll tree[4*n]={0};
        ll lazy[4*n]={0};
        while(m--)
        {
            cin>>i;
            if(i==0)
            {
                cin>>x>>y>>z;
                update(tree,lazy,1,0,n-1,x-1,y-1,z);
            }
            else
            {
                cin>>x>>y;
                cout<<query(tree,lazy,1,0,n-1,x-1,y-1)<<endl;
            }
        }
    }
    return 0;
}
//refer link https://ideone.com/CiYRHi