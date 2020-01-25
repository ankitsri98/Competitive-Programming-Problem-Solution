#include <bits/stdc++.h>
using namespace std;
#define ll long long
void primeFactors(ll n)  
{  
    ll a=0,b=0,c,d=0,p,q;
    p=n;
    for (int i = 2; i <= sqrt(n); i++)  
    {  
        if(n % i == 0)  
        {  
            a=i;d=1;
            n = n/i;  
        }  
        if(d==1)
        break;
    }  
    d=0;
    for (int j = a+1; j <= sqrt(n); j++)  
    {  
        if(n % j == 0)  
        {  
            b=j;d=1;
            n = n/j;  
        }
    if(d==1)
    break;
    }
    //cout<<a<<" "<<b<<endl;
    if(a!=0 && b!=0)
    {
        ll x=(p/(a*b));
        if(x!=a && x!=b && x!=1)
        {
            cout<<"YES"<<endl;
            cout<<a<<" "<<b<<" "<<p/(a*b)<<endl;
        }
        else 
        cout<<"NO"<<endl;
    }
    else 
    cout<<"NO"<<endl;
 
} 
 
int main()
{
    ll t,n,m,k,x,z;
    cin>>t;
    while(t--)
    {
        z=1;
        cin>>n;
        primeFactors(n);
    }
    return 0;
}