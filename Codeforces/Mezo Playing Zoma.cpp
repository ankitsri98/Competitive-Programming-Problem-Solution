#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define ll long long int
int main()
{
    ll n,x=0,y=0,z;
    cin>>n;
    string s;
    cin>>s;
    for(int i=0;i<n;i++)
    {
        if(s[i]=='L')
        x++;
        else if(s[i]=='R')
        y++;
    }
    cout<<x+y+1<<endl;
	return 0;
}
