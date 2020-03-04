#include <bits/stdc++.h>
using namespace std;

int a[1000];
long long int dp[1000];

long long int solve_mixtures(int n){
    if(n==0){
        return dp[n]=0;
    }
    if(n==1){
        return dp[n]=1;
    }
    if(n==2){
        return dp[n]=2;
    }
    if(dp[n]!=-1){
        return dp[n];
    }
    dp[n]=solve_mixtures(n-1)+(n-1)*solve_mixtures(n-2);
    return dp[n];
}
int main() {
    int n;
    cin>>n;
    for(int i=0;i<=1000;i++){
        dp[i]=-1;
    }

    cout<<solve_mixtures(n)<<endl;
}
/*we define the recurrence for the corresponding problem as
F(n) = F(n-1) + (n-1)*F(n-2)
The logic for the above recurrence can be defined by the following points:

The term F(n-1) comes for the case when we choose to go alone then there are n-1 people for which we need to find the solution so we assume this is calculated by recursion.
The term (n-1)*F(n-2) comes because suppose we are choosing to go in a pair then for a nth person we can choose his partner in (n-1) ways (this comes by simple PNC as [n-1]C[1]) So we multiply the factor (n-1) with F(n-2) as F(n-2) denotes the result which will give the answer for the remaining people when we have chosen a pair
So the solution boils down to 3 points

Calculate the answer when we dont pair i.e. F(n-1)
Calculate the answer when we pair i.e F(n-2)
Multiply F(n-2) term with (n-1) because there will be n-1 ways to choose the pair
Hope this helps…


if x is going alone then y has to no choice but to go alone and viceversa so both the cases are same cases so number of grouping for n=2 is 2 ([1,1] , [2] )
*/
