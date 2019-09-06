#include <bits/stdc++.h>
using namespace std;
 
int maxProfit(int price[], int n, int k)
{
    int profit[k+1][n+1];
    
    for (int i = 0; i <= k; i++)
        profit[i][0] = 0;
 
    for (int j= 0; j <= n; j++)
        profit[0][j] = 0;
 
    for (int i = 1; i <= k; i++)//FOR ALL TRANSACTIONS 
    {
        for (int j = 1; j < n; j++)//FOR ALL N 
        {
            int max_so_far =  0;
 
            for (int m = 0; m < j; m++)//FOR PARTICULAR J CALCULATING MAX PROFIT FROM 0 TO J-1 AND STORING IN MAXSO FAR
                max_so_far = max(max_so_far,
                   price[j] - price[m] + profit[i-1][m]);
 
            profit[i][j] = max(profit[i][j-1], max_so_far);//COMARING WHETHER MAX FOR PRESENT J IS MAXIMUM FROM PREVIOUS TRANSACTION
        }
    }
/*	for(int i=0;i<=k;i++)
	{
		for(int j=0;j<=n;j++)
		{
			cout<<profit[i][j]<<"   ";
		}
		cout<<endl;
	}*/
    return profit[k][n-1];
}
//ABOVE CODE COMPLEXITY IS O(K*N^2)
// BELOW IS THE RECURSIVE SOLUTION WITH MEMOIZATION 
// ONGOING TRANSACTION THEN WE CAN ONLY SELL IT OR IGNORE IT
// NO TRANSACTION IS GOING THEN WE CAN IGNORE IT OR BUY....
//SO FOR EVERY INDEX OF ARRAY ....WE HAVE 2 POSSIBILITIES.... WE CAN IGNORE IT OR TAKE IT
int f(int* a,int k,int n,int isgoing,int dp [][12][2])
{
    if(n==0)//BASE CASE
        return 0;
    if(dp[n][k][isgoing]!=-1)
        return dp[n][k][isgoing];
    
    int ans=f(a+1,k,n-1,isgoing,dp);//JUST IGNORING THE PRESENT VALUE AND MOVING FORWARD
    
    if(isgoing)//IF TRANSACTION IS GOING ON THEN 
    {
        int op1=f(a+1,k-1,n-1,0,dp)+a[0];//SO HERE I AM CLOSITING THAT TRANSACTION BY 0.. 
        //AND ALSO DECREASING THE TRANSACTION BY 1...TRANSACTION WAS GOING ON MEANS TILL NOW WE HAVE SOMETHING AND NOW WE HAVE
        //TO SELL IT SO THATS WHY WEARE ADDING A[0] COZ WEARE GETTING THE THE VALUE
        ans=max(ans,op1);
    }
    else
    {
        if(k==0)
        {
            ans=0;
        }
        else
        {
            int op2=f(a+1,k,n-1,1,dp)-a[0];//SO HERE TRANSACTION IS NOT GOING ON SO WE HAVE TO BUY IT 
            //DUE TO WHICH OUR VALUE WILL DECREASE... K WILL NOT REDUCE COZ IT STILL GOING ON AND IS NOT 
            //SOLD WHEN A TRANSACTION IS OVER WHEN THE ITEM IS SOLD AWAY
            ans=max(ans,op2);
        }
    }
    dp[n][k][isgoing]=ans;
    return ans;//FINALLY STORING ANSWER
}
int main()
{
    int k,n,t;
    
    cin>>t;
    
    for(int j = 0; j < t; j++)
    {
    	cin>>k;
    	cin>>n;
    	int price[n];
    	
        for(int i = 0; i < n; i++)
    		cin>>price[i];
        int dp[32][12][2];
        for(int i=0;i<=31;i++)
        {
            for(int j=0;j<=11;j++)
            {
                dp[i][j][0]=-1;
                dp[i][j][1]=-1;
            }
        }
        cout<<f(price,k,n,0,dp)<<endl;
    	//cout<< maxProfit(price, n, k)<<endl;
    }
    return 0;
}