PROBLEM:-
Thanks a lot for helping Harry Potter in finding the Sorcerer's Stone of Immortality in October. Did we not tell you that it was just an online game ? uhhh! now here is the real onsite task for Harry. You are given a magrid S ( a magic grid ) having R rows and C columns. Each cell in this magrid has either a Hungarian horntail dragon that our intrepid hero has to defeat, or a flask of magic potion that his teacher Snape has left for him. A dragon at a cell (i,j) takes away |S[i][j]| strength points from him, and a potion at a cell (i,j) increases Harry's strength by S[i][j]. If his strength drops to 0 or less at any point during his journey, Harry dies, and no magical stone can revive him.

Harry starts from the top-left corner cell (1,1) and the Sorcerer's Stone is in the bottom-right corner cell (R,C). From a cell (i,j), Harry can only move either one cell down or right i.e., to cell (i+1,j) or cell (i,j+1) and he can not move outside the magrid. Harry has used magic before starting his journey to determine which cell contains what, but lacks the basic simple mathematical skill to determine what minimum strength he needs to start with to collect the Sorcerer's Stone. Please help him once again.

 

Input (STDIN):
The first line contains the number of test cases T. T cases follow. Each test case consists of R C in the first line followed by the description of the grid in R lines, each containing C integers. Rows are numbered 1 to R from top to bottom and columns are numbered 1 to C from left to right. Cells with S[i][j] < 0 contain dragons, others contain magic potions.

Output (STDOUT):
Output T lines, one for each case containing the minimum strength Harry should start with from the cell (1,1) to have a positive strength through out his journey to the cell (R,C).

Constraints:
1 ≤ T ≤ 5

2 ≤ R, C ≤ 500

-10^3 ≤ S[i][j] ≤ 10^3

S[1][1] = S[R][C] = 0

 

Sample Input:
3
2 3
0 1 -3
1 -2 0
2 2
0 1
2 0
3 4
0 -2 -3 1
-1 4 0 -2
1 -2 -3 0

SOLUTIONS:-

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



