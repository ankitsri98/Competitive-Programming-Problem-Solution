#include <bits/stdc++.h>
using namespace std;

int f(int* a,int id,int n,int x,int*c,int** dp)
{
    if(id>=n)//PROBLEM IS TO MAKE PLANE CREWS WHICH CONTAINS A PILOT AND ASSISTANT 
        return 0;
    if(dp[id][x]!=-1)
        return dp[id][x];
    int ans;
    if(x==0)//FIRST SHOULD BE ASSISTANT COZ IYS SALARY SHOULD BE MINIMUM
    {
        ans=a[id]+f(a,id+1,n,1,c,dp);
        dp[id][x]=ans;
        return ans;
    }
    else if(x==n-id)//CPTAIN COMES
    {
        ans=c[id]+f(a,id+1,n,x-1,c,dp);//X IS MAINTAINED BY  A-C
        dp[id][x]=ans;
        return ans;
    }
    else
    {
        int op1=a[id]+f(a,id+1,n,x+1,c,dp);
        int op2=c[id]+f(a,id+1,n,x-1,c,dp);
        ans=min(op1,op2);
        //dp[n][x]=ans;
        //return ans;
    }
  /*  for(int i=0;i<=n;i++)
     {
         for(int j=0;j<=n;j++)
         {
             cout<<dp[i][j]<<"   ";
         }
         cout<<endl;
     }*/
    dp[id][x]=ans;
    return ans;
}
int main()
{
    int i,j,k,l,x,z,m,n;
    cin>>n;
    int c[n];
    int a[n];
    for(i=0;i<n;i++)
        cin>>c[i]>>a[i];
    int** dp=new int*[n+1];
    for(int i=0;i<=n;i++)
    {
        dp[i]=new int[n/2+1];
    }
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=n/2;j++)
        {
            dp[i][j]=-1;
        }
    }
    cout<<f(a,0,n,0,c,dp)<<endl;
    for(int i=0;i<=n;i++)
    {
        delete [] dp[i];
    }
    delete [] dp;
    return 0;
}



/*#include <bits/stdc++.h>
using namespace std;

int f(int* a,int n,int x,int*c,int** dp)
{
    if(n<0)
        return 0;
    if(dp[n][x]!=-1)
        return dp[n][x];
    int ans;
    if(x==0)
    {
        ans=a[0]+f(a+1,n-1,1,c+1,dp);
        dp[n][x]=ans;
        return ans;
    }
    else if(x==n)
    {
        ans=c[0]+f(a+1,n-1,x-1,c+1,dp);
        dp[n][x]=ans;
        return ans;
    }
    else
    {
        int op1=a[0]+f(a+1,n-1,x+1,c+1,dp);
        int op2=c[0]+f(a+1,n-1,x-1,c+1,dp);
        ans=min(op1,op2);
        //dp[n][x]=ans;
        //return ans;
    }
    for(int i=0;i<=n;i++)
     {
         for(int j=0;j<=n;j++)
         {
             cout<<dp[i][j]<<"   ";
         }
         cout<<endl;
     }
    dp[n][x]=ans;
    return dp[n][x];
}
int main()
{
    int i,j,k,l,x,z,m,n;
    cin>>n;
    int c[n];
    int a[n];
    for(i=0;i<n;i++)
        cin>>c[i]>>a[i];
    int** dp=new int*[n+1];
    for(int i=0;i<=n;i++)
    {
        dp[i]=new int[n/2+1];
    }
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=n/2;j++)
        {
            dp[i][j]=-1;
        }
    }
    cout<<f(a,n,0,c,dp)<<endl;
    for(int i=0;i<=n;i++)
    {
        delete [] dp[i];
    }
    delete [] dp;
    return 0;
}
*/

/*#include <bits/stdc++.h>
using namespace std;
//long long dp[10000][101];
typedef long long ll;
long long min_sal(long* cap, long* assis, int n, int x, int i, int** dp){
	
	if(i==n){
		return 0;
	}
	
	//cout<<"dp[i][x]="<<dp[i][x]<<endl;
	
	if(dp[i][x]>0)
		return dp[i][x];
	//cout<<"func Called\n";
	
	long long ans;
	if(x==0)
		ans= assis[i]+min_sal(cap, assis, n, x+1,i+1, dp);
	
	else if(x==n-i)
		ans=cap[i]+min_sal(cap, assis, n, x-1, i+1, dp);
	
	else
		ans=min(assis[i]+min_sal(cap, assis, n, x+1, i+1, dp), cap[i]+min_sal(cap, assis, n, x-1, i+1, dp));
	
	dp[i][x]=ans;
	return ans;
}

int main(){

	int n;
	cin>>n;

	long cap[n], assis[n];
	
	for(int i=0;i<n;i++)
		cin>>cap[i]>>assis[i];
	
	int** dp=new int*[n];
	
	for(int i=0;i<n;i++)
		dp[i]=new int[n/2+1];
	
	// memset(dp, -1, sizeof(int)*(n*n/2));
	
	// cout<<"func called\n"<<sizeof(dp[n-1][0])<<endl<<n/2+1<<endl<<dp[0][0];
	// cout<<dp[0][0]<<endl;
	for(int i=0;i<n;i++)
		for(int j=0;j<=n/2;j++)
			dp[i][j]=0;

	
	cout<<min_sal(cap, assis, n, 0, 0,dp);
	
	for(int i=0;i<n;i++)
		delete [] dp[i];
	
	delete [] dp;

}
*/