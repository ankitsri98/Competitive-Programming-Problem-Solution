#include <bits/stdc++.h>
using namespace std;

int main()
{
    
    int n,m,k,l,i,x,z,s,y;
    cin>>n;
    cin>>m;
    int start[n+2]={0},end[n+2]={0};
    while(m--)
    {
        cin>>x>>y;
        start[x]++;
        end[y]++;
    }
    int totalcoin[1000005]={0};
    
    for(i=1;i<=n;i++)
    {
        totalcoin[i]=start[i]-end[i-1]+totalcoin[i-1];//THIS IS FOR
        //HOW MANY COIN EACH BOX CONTAIN AFTER M DAYS
    }
    /*for(i=1;i<=n;i++)
    {
        cout<<totalcoin[i]<<" ";
    }
    cout<<endl;
    */
    int atleastcoin[1000005]={0};
    for(i=1;i<=n;i++)
    {
        atleastcoin[totalcoin[i]]++;//THIS CONTAINS FREQUENCY FOR X COINS 
    }
   /* for(i=0;i<=n;i++)
    {
        cout<<atleastcoin[i]<<" ";
    }
    cout<<endl;*/
    for(i=n-1;i>=0;i--)
    {
        atleastcoin[i]+=atleastcoin[i+1];//ATLEAST X COINS JUST TAKEN SUM 
    }
    /*for(i=0;i<=n;i++)
    {
        cout<<atleastcoin[i]<<" ";
    }
    cout<<endl;*/
    cin>>s;
    while(s--)
    {
        cin>>z;
        cout<<atleastcoin[z]<<endl;
    }
    return 0;
}

