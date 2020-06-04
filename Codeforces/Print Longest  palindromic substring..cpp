class Solution {
public:
    string longestPalindrome(string s) {
        if(s==""){
            return "";//handling the corner case
        }
        int n;
        pair<int ,int > p;//just to store the starting index and length of largest substring for future use
        n=s.length();
        string str=s;
        int c=1;
	    int arr[n+2][n+2];
        memset(arr,0,sizeof(arr));
	    for(int i=0;i<n;i++){
	        arr[i][i]=1;
            p.first=i;
            p.second=1;
	    }
        
	    string ans;
        ans=s[0];
	    for(int i=2;i<=n;i++){//lengths of substring
	        for(int j=0;j<n;j++){
	            int k=i+j-1;
                if(k>n-1){
                    continue;
                }
	            if(str[j]==str[k]){
	                if(i==2 || arr[j+1][k-1]==1){
	                    arr[j][k]=1;
                        
                        //ans=s.substr(j,i);//here i have not calc. the substring as it will incresse complexity
                        p.first=j;
                        p.second=i;
                        
	                    c=max(c,i);// extra info for cal. the length of of max substring
	                }
	            }
	        }
	    }
	    return s.substr(p.first,p.second);
    }
};