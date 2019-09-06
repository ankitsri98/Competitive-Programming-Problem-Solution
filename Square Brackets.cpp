#include <bits/stdc++.h>
using namespace std;
int dp[1001][1001];
int braket(int o,int c,int n,int f[])
{

    if(o>n || c>n)//BEST USE OF MEMOIZATION ...REMEMBER THIS FOR THAT
        return 0;
    if(o==n&& c==n)//2*N KI STRING BANAI HAI TO AGAR O==N & c==N TOH KHATM HO GAI BAAT
        return 1;
    if(dp[o][c]!=-1)
        return dp[o][c];
    int ans;
    if(o==c || f[o+c]==1){//F O==C THEN AGLA TOH AB OPEN HI HOGA NA....AND O+C IS THE CURRENT INDEX KAISE
        ans= braket(o+1,c,n,f);//O+C DENOTE KI KITNE BRACKETS AA CHUKE HAIN TOH UNKA SUM INDEX BATA RAHA HAI
        dp[o][c]=ans;//-->KEEP STORING AT EACH CALL
    return ans;
}
    else if(o==n){
        ans= braket(o,c+1,n,f);//HAR 2*N STRING ME N 'O' HAIN AND N 'C' HAIN TOH AGAR O KHATM HO GAI YAANI N
        dp[o][c]=ans;//TOH AB CLOSING BRACKET AAIGA NA
        return ans;
    }else
    {
        int op1=braket(o+1,c,n,f);//CALL DONO FUNCTION
        int op2=braket(o,c+1,n,f);
        ans= op1+op2;
        dp[o][c]=ans;
        return ans;
    }
}
int main()
{
    int t,n,m,i,j,l,x,z,k;
    cin>>t;
    while(t--)
    {
        cin>>n>>k;
        int a[k];
        
        memset(dp,-1,sizeof(dp));
        for(i=0;i<k;i++)//INPUTTING POSITION OF OPEN BRACKETS
            cin>>a[i];
        int flag[2*n+1]={0};
        
        for(i=0;i<k;i++)//MAINTAING PRESENCE OF POSITION
        {
            flag[a[i]-1]++;
        }
        cout<<braket(0,0,n,flag)<<endl;
    }
    return 0;
}
