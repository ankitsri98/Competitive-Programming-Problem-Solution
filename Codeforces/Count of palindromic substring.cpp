
int n;
class Solution {
public:
    int countSubstrings(string s) {
        n=s.length();
        string str=s;
        int c=0;
	    int arr[n+2][n+2];
        memset(arr,0,sizeof(arr));
	    for(int i=0;i<n;i++){
	        arr[i][i]=1;
	        c++;
	    }
	    
	    for(int i=2;i<=n;i++){
	        for(int j=0;j<n;j++){
	            int k=i+j-1;
                if(k>n-1){
                    continue;
                }
	            if(str[j]==str[k]){
	                if(i==2 || arr[j+1][k-1]==1){
	                    arr[j][k]=1;
	                    c++;
	                }
	            }
	        }
	    }
	    return c;
    }
};