#include <bits/stdc++.h>
using namespace std;
map<long int ,long int> mp;
long int maxi(long int n){
    if(n<=0){
        return 0;
    }
    if(n==1){
        return 1;
    }
    if(mp.count(n)){
        return mp[n];
    }
    long int a=maxi(n/2);
    long int b=maxi(n/3);
    long int c=maxi(n/4);
    //cout<<"a: "<<a<<"  b: "<<b<<" c: "<<c<<endl;
    mp[n]=max(n,a+b+c);
    //cout<<n<<"  --->   "<<mp[n]<<"   "<<endl;
    return mp[n];
}
int main() {
    long int n;cin>>n;
    cout<<maxi(n);

}
