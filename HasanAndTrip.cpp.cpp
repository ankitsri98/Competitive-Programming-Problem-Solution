#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,m,i,j,k,l,s;
    cin>>n;
    int a[n],b[n],c[n];
    double dp[n]={0};
    for(i=0;i<n;i++)
    {
        cin>>a[i]>>b[i]>>c[i];
    }
    double x,z;
    //IN THIS QUE. WE HAVE TO REACH NTH CITY FROM FIRST CITY .IF WE MOVE TO ANY
    //CITY J FROM I BTW 1 TO N THEN ( F[I] + F[J] - DIST ) BTW THEM SHOULD
    //MAXIMUM
    dp[0]=c[0];//FOR FIRST THE HAPPINESS IS F[0]
    for(i=1;i<n;i++)
    {
        dp[i]=INT_MIN;
        for(j=0;j<i;j++)//HERE WE ARE LOOKING FROM 0 TO I THAT ...FROM WHERE
        {//CAN WE REACH I WITH MAX THIS VALUE AND IN THE END WE ADD F[I]
            //ITS SAME LIKE ABOVE EXP- LIKE (F[I]-DIST)+F[J] .
            dp[i]=max(dp[i],  dp[j]-sqrt(pow((a[i]-a[j]),2)+pow((b[i]-b[j]),2)) );
            
        }
        dp[i]+=c[i];
    }
    cout<<fixed<<setprecision(6);
    cout<<dp[n-1]<<endl;
    return 0;
}
