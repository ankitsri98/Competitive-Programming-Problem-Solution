#include<iostream>
#include<cstring>
using namespace std;


int lcsi(string s1, string s2) {
	int m = s1.length();
	int n = s2.length();
	int** dp = new int*[m + 1];
	for (int i = 0; i <= m; i++) {
		dp[i] = new int[n + 1];
	}
	for (int i = 0; i <= m; i++) {//BASE CASE WHEN ANY OF THE STRING IS ZERO THEN IT WILL BE MADE EQUAL TO THE OTHER ONE
		dp[i][0] = i;             //IN COST OF LENGTH OF OTHER STRING
	}
	for (int i = 0; i <=n ;i++) {
		dp[0][i] = i;
	}

	for (int i = 1; i <= m; i++) {
		for (int j = 1; j<= n; j++) {
			if (s1[m - i] == s2[n - j]) {//IF 2 CHARACTERS ARE EQUAL THEN DO NOTHIN ADD OVERWRITE VALUE OF DIAGNOL
				dp[i][j] =  dp[i - 1][j - 1];
			}	else {
				dp[i][j] = 1+min(dp[i - 1][j - 1],min(dp[i - 1][j], dp[i][j - 1]));//2ND AND 3RD CONDITION IS FOR INSERTION AND
			} //AND DELETION AND 1ST ONE IS FOR  CHANGING CHARACTER AND AGAIN CHECKING IF ITS EQUAL OR NOT AND SELECTING THE MINNIMUM
		}// FOR ANY OF THESE OPERATION COST IS INCREASED BY ONE 
	}

	int ans =  dp[m][n];
	// delete 2d array
	for (int i =0; i <=  m; i++) {
		delete [] dp[i];
	}
	delete [] dp;
	return ans;
}

int editDistance(string s1, string s2){

  /*  Don't write main().
   *  Don't read input, it is passed as function argument.
   *  Return output and don't print it.
   *  Taking input and printing output is handled automatically.
   */
    
    return lcsi(s1,s2);

}
