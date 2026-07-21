class Solution {
public:
    int checker(vector<int>& nums, int start, int end){
        if(start > end) return 0;
        
        int n = end-start+1;
        if(n==1) return nums[start];

        int prev2 = nums[start];
        int prev1 = max(nums[start], nums[start+1]);
        for(int i=start+2; i <= end; i++){
            int curr = max(prev1, prev2+nums[i]);
            prev2 = prev1;
            prev1 = curr;
        }

        return prev1;
    }
    int rob(vector<int>& nums) {
        int n = nums.size();

        if(n==1) return nums[0];
        int take = checker(nums, 0, n-2);
        int skip = checker(nums, 1, n-1);

        return max(take, skip);
    }
};
