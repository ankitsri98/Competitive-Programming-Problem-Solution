#include <bits/stdc++.h>
using namespace std;
#define m 1000000007

int total(int* arr,int n){
	long long int* dp=new long long int[n+1];
    for(int i=0;i<=n;i++){
        dp[i]=0;
    }
	dp[0]=1;dp[1]=1;
	for(int i=2;i<=n;i++){
        if(arr[i]>0){
            dp[i]=dp[i-1];
        }
		int x=arr[i-1],z=arr[i];
        x=x*10+z;
        //cout<<x<<endl;
		if(x>=10&&x<=26){
			dp[i]=(dp[i]+dp[i-2]);
		}
	}
	return dp[n];
}
int main()
{
    string s;
    while(true)
    {
        cin>>s;
        if(s=="0")
            break;
        else
        {
            int n=s.size();
            int* arr=new int[n+1];
            arr[0]=0;
            for(int i=1;i<=n;i++){
            	arr[i]=s[i-1]-48;
            }
            cout<<total(arr,n)<<endl;
        }
    }
    return 0;
}