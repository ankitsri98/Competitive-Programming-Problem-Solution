
int smallestSuperSequence(char str1[], int len1, char str2[], int len2) { 
  /* Don't write main().
     Don't read input, it is passed as function argument.
     Return output and don't print it.
     Taking input and printing output is handled automatically.
  */
    int** dp=new int*[len1+1];
    for(int i=0;i<=len1;i++)
    {
        dp[i]=new int[len2+1];
    }
    int x=0;
    for(int i=len1;i>=0;i--)//PROBLEM IS SIMILAR TO LCS //USED BOTTOM UP APPROACH
    {
        dp[i][len2]=x++;
    }
    x=0;
    for(int i=len2;i>=0;i--)//JUST A BIT DIFFERENT FROM LCS IN THE FORM KI LOOK DOWN
    {
        dp[len1][i]=x++;
    }
    for(int i=len1-1;i>=0;i--)
    {
        for(int j=len2-1;j>=0;j--)
        {
            if(str1[i]==str2[j])
            {
                dp[i][j]+=dp[i+1][j+1]+1;
            }
            else
            {
                dp[i][j]=min(dp[i+1][j],dp[i][j+1])+1;//WHEN 2 CHARS ARE NOT EQUAL THEN ALSO ONE OF THEM IS INCLUDED
            }
        }
    }
  /*  for(int i=0;i<=len1;i++)
    {
        for(int j=0;j<=len2;j++)
        {
            cout<<dp[i][j]<<"  ";
        }
        cout<<endl;
    }*/
    int ans=dp[0][0];
    for(int i=0;i<=len1;i++)
    {
        delete [] dp [i];
    }
    delete [] dp;
    return  ans;
}
int smallestSuperSequence(char str1[], int len1, char str2[], int len2) { 
  /* Don't write main().
     Don't read input, it is passed as function argument.
     Return output and don't print it.
     Taking input and printing output is handled automatically.
  */
    int** dp=new int*[len1+1];
    for(int i=0;i<=len1;i++)
    {
        dp[i]=new int[len2+1];
    }
    int x=0;
    for(int i=len1;i>=0;i--)//PROBLEM IS SIMILAR TO LCS //USED BOTTOM UP APPROACH
    {
        dp[i][len2]=x++;
    }
    x=0;
    for(int i=len2;i>=0;i--)//JUST A BIT DIFFERENT FROM LCS IN THE FORM KI LOOK DOWN
    {
        dp[len1][i]=x++;
    }
    for(int i=len1-1;i>=0;i--)
    {
        for(int j=len2-1;j>=0;j--)
        {
            if(str1[i]==str2[j])
            {
                dp[i][j]+=dp[i+1][j+1]+1;
            }
            else
            {
                dp[i][j]=min(dp[i+1][j],dp[i][j+1])+1;//WHEN 2 CHARS ARE NOT EQUAL THEN ALSO ONE OF THEM IS INCLUDED
            }
        }
    }
  /*  for(int i=0;i<=len1;i++)
    {
        for(int j=0;j<=len2;j++)
        {
            cout<<dp[i][j]<<"  ";
        }
        cout<<endl;
    }*/
    int ans=dp[0][0];
    for(int i=0;i<=len1;i++)
    {
        delete [] dp [i];
    }
    delete [] dp;
    return  ans;
}