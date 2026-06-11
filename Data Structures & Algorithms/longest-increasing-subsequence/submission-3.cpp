class Solution {
public:
    vector<int> dp;
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return 1;
        dp.assign(n, 1); //every one has a minimum of 1 as longest seq
        for(int i=0; i < n; i++){
            for(int j=0; j < i; j++){
                if(nums[i] > nums[j]){
                    dp[i] = max(dp[i], 1+dp[j]);
                }
            }
        }
        int maxi = 0;
        for(int ele : dp){
            maxi = max(maxi, ele);
        }
        return maxi;
    }

};
