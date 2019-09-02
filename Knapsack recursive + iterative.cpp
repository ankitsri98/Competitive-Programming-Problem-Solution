
#include<bits/stdc++.h>
using namespace std;

int ks(int* weights, int* values, int n, int maxWeight,int** dp)
{
    if(n==0||maxWeight==0)
        return 0;
    if(dp[n][maxWeight]!=-1)
        return dp[n][maxWeight];
    int ans;
    if(weights[n-1]>maxWeight)
    {
        ans= ks( weights, values, n-1, maxWeight,dp);
    }
    else if(weights[n-1]<=maxWeight)
    {
        ans= max(values[n-1]+ks( weights, values, n-1, maxWeight-weights[n-1],dp),ks( weights, values, n-1, maxWeight,dp));
    }
    dp[n][maxWeight]=ans;
    return ans;

}
//ABOVE IS MY RECURSIVE CODE ANSD BELOW IS MY RECURSIVE ONE

int ks(int wei[],int val[],int n,int w)
{
    int** dp=new int*[n+1];
    for(int i=0;i<=n;i++)
    {
        dp[i]=new int[w+1];
    }

    for(int i=0;i<=n;i++){//BASE CONDITIONS
        dp[i][0]=0;
    }
    for(int i=0;i<=w;i++){
        dp[0][i]=0;
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<=w;j++)//LOOK MOST IMPORTANTLY THIS LOOP IS FOR ALL WEIGHTS FROM 0 T0 MAX AND FOR PARTICULAR WEIGHT THEY ARE CHECKING FOR COMDITION wei[i-1]<=j
        {
            dp[i][j]=dp[i-1][j];//DEALS WITH TAKING OR LEAVING A PARTICULAR ITEM ---THIS MEANS LEAVING PRESENT ITEM J=WEIGHT REMAIN SAME THEN COPY PAST VALUE(I-1)
            
            if(wei[i-1]<=j)//THIS OVERFLOW CONDITION IF WEI[I-1]>W THEN IT WILL BE OUT OF BOUND I.E BELOW 0 INDEXING
            {
                dp[i][j]=max(dp[i][j],val[i-1]+dp[i-1][j-wei[i-1]]);//HERE CONSIDERING THE ITEM THEN WEIGHT WILL DECREASE AND
                
                //VALUE WILL BE INCLUDED DOR I WHICH IS AT I-1 POSITON IN VALUE ARRAY
            }
        }
    }
    int z;
 /*   for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=w;j++)
        {
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }*/
    int ans=dp[n][w];

    //cout<<ans1<<endl;
    for(int i=0;i<=n;i++)
    {
        delete[] dp[i];
    }
    delete [] dp;
    
    return ans;
    
}
int knapsack(int* weights, int* values, int n, int maxWeight){

  /* Don't write main().
   *  Don't read input, it is passed as function argument.
   *  Return output and don't print it.
   *  Taking input and printing output is handled automatically.
  */
    


   // return knapsnack(weights,values,n,maxWeight);
    return ks(weights,values,n,maxWeight);
}
