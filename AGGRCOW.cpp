problem:
Farmer John has built a new long barn, with N (2 <= N <= 100,000) stalls. The stalls are located along a straight line at positions x1,...,xN (0 <= xi <= 1,000,000,000).

His C (2 <= C <= N) cows don't like this barn layout and become aggressive towards each other once put into a stall. To prevent the cows from hurting each other, FJ wants to assign the cows to the stalls, such that the minimum distance between any two of them is as large as possible. What is the largest minimum distance?
Input
t – the number of test cases, then t test cases follows. 
* Line 1: Two space-separated integers: N and C
* Lines 2..N+1: Line i+1 contains an integer stall location, xi
Output
For each test case output one integer: the largest minimum distance.
Example
Input:

1
5 3
1
2
8
4
9
Output:

3
Output details:

FJ can put his 3 cows in the stalls at positions 1, 4 and 8, 
resulting in a minimum distance of 3.
Solution:-
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
ll n;
ll binarys(ll a[],ll l,ll r,ll c)
{
    ll mid,x,y=c,ans;
    while(r>=l)
    {
        mid=l+(r-l)/2;// mid is a distance to checked
        x=a[0];
        y=c;
        for(ll i=1;i<n;i++)
        {
            ll diff=a[i]-x;
            //cout<<"diff : "<<diff<<endl;
            if(diff>=mid)
            {
                y=y-1;
                x=a[i];
                //cout<<"new cow pos: "<<x<<endl;
            }
            if(y==0)
                break;
        }
        if(y==0)
        {
            l=mid+1;
            ans=mid;
        }
        else
            r=mid-1;
        //cout<<l<<" "<<r<<" "<<mid<<endl;
    }
    return ans;
}
int main()
{
    ll m,c,x,z,k,l,i,j,r;
    ll t;
    cin>>t;
    while(t--)
    {
        cin>>n>>c;
        ll a[n];
        for(i=0;i<n;i++)
        {
            cin>>a[i];
        }
            sort(a,a+n);
            l=0;
            r=a[n-1]-a[0];
        //cout<<l<<" "<<r<<endl;
            z=binarys(a,l,r,c-1);
        cout<<z<<endl;
    }
}