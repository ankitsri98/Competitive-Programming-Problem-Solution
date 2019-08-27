#include <bits/stdc++.h>
using namespace std;
#define ll long long int 
int main()
{
    ll n,m,k,i,j,x,z=0;
    cin>>n;
    cin>>k;
    ll a[n+1];
    ll presum[n+2]={0};
    for(i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    sort(a+1,a+n+1);
   /* for(i=1;i<=n;i++)
    {
        cout<<a[i]<<"  ";
    }
    cout<<endl;*/
    presum[1]=a[1];
    for(i=2;i<=n;i++)
    {
        presum[i]=presum[i-1]+a[i];
    }
    /*for(i=1;i<=n;i++)
    {
        cout<<presum[i]<<"  ";
    }
    cout<<endl;*/
    ll ksum[n+2];
    ksum[1]=0;ksum[2]=a[2]-a[1];
    z=ksum[2];
    for(i=2;i<k;i++)
    {
        z+=i*a[i+1] - presum[i];
    }
    //cout<<"z: "<<z<<endl;
    x=1;
    ll cost=z;
    ll mini=z;
    for(i=k+1;i<=n;i++)
    {
        cost=cost-2*(presum[i-1]-presum[x]) + (k-1)*a[x] + (k-1)*a[i];
       // cout<<cost<<"   "; 
        if(cost<mini)
            mini=cost;
        x++;
       
    }
    //cout<<endl;
    cout<<mini<<endl;
    return 0;
    
}
