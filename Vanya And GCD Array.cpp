#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ll n,m,k,i,j,x,z;
    cin>>n;
    ll a[n];
    for(i=0;i<n;i++)
    {
        cin>>a[i];
    }
    ll dp[n][101]={0};
    
    dp[0][a[0]]=1;
    x=dp[0][1];
    for(i=1;i<n;i++)
    {
        for(j=i-1;j>=0;j--)//THIS LOOP IS FOR FINDING J WHICH IS LENGTH OF SUBSEQUENCE WHICH
            //IS JUST POSSIBLE
        {
            if(a[j]<a[i])
            {
                for(k=1;k<=100;k++)//SO FOR THAT LENGTH J WE WILL TRAVERSE THROUGH ALL THE GCDS 
                    //WITH THE LOGIC THAT IF SEQUENCE OF LENGTH J HAS GCD K(CAN END HAVING ANY GCD FROM 1 TO 100)
                    //THEN AFTER TAKING GCD OF IT
                    //WITH A[I] RESULTS IN GCD FROM 1 TO 100(RANGE) ...IN WHICH WE ONLY NEED TO FIND THE 
                    //ANSWER FOR GCD 1 
                {
                    z=__gcd(a[i],k);
                    dp[i][z]+=dp[j][k];
                    dp[i][z]=dp[i][z]%1000000007;
                }
            }
        }
        dp[i][a[i]]++;
        x+=dp[i][1];
        x=x%1000000007;
    }
   /* for(i=0;i<n;i++)
    {
        for(j=1;j<=100;j++)
        {
            cout<<dp[i][j]<<"   ";
        }
        cout<<endl;
    }*/
    cout<<x<<endl;
    return 0;
}
/*
To come up with the dynamic programming solution, 
let us ask the usual question: Suppose that we have found the answer 
for the first i−1 elements, how do we extend it to a solution for the first i elements?

Well, every valid sequence either involves the last element or not.
 The sequences which do not contain the ith element have already been 
 counted in the previous step, so we only need to look at subsequences which end at i. 
 Say the previous element in the subsequence is A[j]. Then we want

A[j]<A[i]
If the gcd of subsequence terms up to A[j] is x, gcd(x,A[i])=1
This means that we need to solve the slightly more general problem
 of counting the subsequences ending at position i with gcd g. 
 So we define our DP function accordingly:

f(i,g) = number of subsequences ending at position i with gcd equal to g

The recurrence is now pretty obvious: For all j<i such that A[j] 
is also less than A[i], and for all g′ such that gcd(g′,A[i])=g,
 we have to add f(j,g′) to f(i,g). Additionally, if g is equal to A[i],
  we have the one-element sequence.
  */