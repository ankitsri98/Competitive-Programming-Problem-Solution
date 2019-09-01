#include <bits/stdc++.h>
using namespace std;
int dp[123][123][123];
int lcs(string s1,string s2 , int i ,int j,int k)
{
    if(k==0)//SIMPLE BASE CASE 
        return 0;
    if(i>=s1.length() || j>=s2.length())//AS I AM STARTING FROM 0 SO IF ANYONE STRING IT CROSSES LENGTH
        return -5; //THEN RETURN A -VE  VALUE
    if(dp[i][j][k]!=-1)//THIS IS FOR DISPLAYING IF ALREADY STORED
        return dp[i][j][k];
    int ans;
    if(s1[i]==s2[j])//MAIN
    {
        int op1=lcs(s1,s2,i+1,j+1,k-1);//IF I INCLUDE THE MATCHED CHARACTER INDEXES INCREASES AND LEN DECREASES
        op1=op1==-5?-5:op1+(int)s1[i];//THIS IS KIND OF BASE COND. LIKE IF CHARACTER GOT MATCHED AT LAST POSITION THEN 
        //BUT NOW CHECK WETHER STRING FINISH TOH NHI HO GAI..IF NOT THEN ONLY INCREASE ASCII VALUE
        int op2=lcs(s1,s2,i+1,j,k);//THESE ARE FO KI CONDITION MATCH TOH HO GAI BUT WE DON'T TAKE THAT 
        //VARIABLE COZ WE HAVE TO MAXIMIZE THE SUM OF ASCII VALUES
        int op3=lcs(s1,s2,i,j+1,k);
        ans= max(op1,max(op2,op3));
    }
    else
    {
        ans= max(lcs(s1,s2,i+1,j,k),lcs(s1,s2,i,j+1,k));//THESE ARE WHEN CHARACTERS ARE NOT EQAUL
    }
    dp[i][j][k]=ans;
    return ans;
}
int main()
{
    int n,m,k,i,x,z,j;
    int t;
    cin>>t;
    while(t--)
    {
        string s1,s2;
        cin>>s1>>s2;
        cin>>k;
        for(i=0;i<123;i++)
        {
            for(j=0;j<123;j++)
            {
                for(m=0;m<123;m++)
                {
                    dp[i][j][m]=-1;
                }
            }
        }
        x=lcs(s1,s2,0,0,k);
        if(x<0)
            cout<<0<<endl;//VALUE CAN BE NEGATIVE IN CASE NO K LENGTH IS FOUND
        else
            cout<<x<<endl;
    }
    
    return 0;
}
