vector<int > adj[1000];
class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n=nums.size();
        if(n==0){
            return {};
        }
        sort(nums.begin(),nums.end());//to reduce checking of a[j]%a[i] j<i
        vector<int > v;
        //take 2 vectors 1 for length and other for track of prev element
        vector<int > dp(n,1);
        vector<int > prev(n,-1);
        int max_len=0;
        for(int i=0;i<nums.size();i++){
            for(int j=0;j<i;j++){
                if(nums[i]%nums[j]==0 && dp[i]<dp[j]+1){
                    dp[i]=dp[j]+1;
                    prev[i]=j;
                }
            }
            if(dp[i]>dp[max_len]){
                max_len=i;
            }
        }
        //forming subset
        int t=max_len;//t is index from where we start inserting elements
        while(t>=0){
            v.push_back(nums[t]);
            t=prev[t];
        }
    
        
        return v;
        
    }
    
};
