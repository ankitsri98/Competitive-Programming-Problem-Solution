
#include<bits/stdc++.h>
using namespace std;

int min_cost(int** input,int m, int n)
{
    int** dp=new int*[m];
    for(int i=0;i<m;i++)
    {
        dp[i]=new int[n];//CREATING DYNAMIC ARRAY 2-D
    }
    dp[m-1][n-1]=1;//THIS IS FOR LAST ELEMENT ONLY 1 IS POSSIBLE THERE TO SURVIVE
    for(int i=m-2;i>=0;i--)
    {
        dp[i][n-1]=dp[i+1][n-1]-input[i][n-1];//FILLING LAST COLUMN HERE ROWS ARE CHANGING
        if(dp[i][n-1]<=0)
            dp[i][n-1]=1;
    }
    for(int i=n-2;i>=0;i--)
    {
        dp[m-1][i]=dp[m-1][i+1]-input[m-1][i];//FILLING LAST ROW COLUMNS ARE CHANGING
        if(dp[m-1][i]<=0)
            dp[m-1][i]=1;
    }
    for(int i=m-2;i>=0;i--)//THESE 2 LOOPS ARE FOR FILLING REMAINING ARRAY
    {
        for(int j=n-2;j>=0;j--)//BY USIND THE MINIMUM OF TWO ELEMENTS
        {
            dp[i][j]=min(dp[i+1][j],dp[i][j+1])-input[i][j];
            if(dp[i][j]<=0)
                dp[i][j]=1;
        }
    }
    /*    for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                cout<<dp[i][j]<<" ";
            }
            cout<<endl;
        }*/
    return dp[0][0];
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int r,c;
        cin>>r>>c;
        int** input =new int*[r];//CREATING DYNAMIC 2-D ARRAY
        for(int i=0;i<r;i++)
        {
            input[i]=new int[c];
        }
        for(int i=0;i<r;i++)
        {
            for(int j=0;j<c;j++)
            {
                cin>>input[i][j];
            }
        }
        cout<<min_cost(input,r,c)<<endl;//HERE SIZE IS PASSED
        for(int i=0;i<r;i++)
        {
            delete[] input[i];
        }
        delete[] input;
    }

}



