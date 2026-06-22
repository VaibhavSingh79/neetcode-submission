class Solution {
public:
    vector<vector<int>> memo;
    bool solve(vector<int> &nums, int index, int target){
        //rule of recursion -> write base cases first before you traverse
        if(target == 0) return true;
        if(target < 0) return false; //it means this route was not correct but ques doesn't end here
        if(index == nums.size()) return false; //reached the end

        if(memo[index][target] != -1) return memo[index][target];

        //now we can write the logic for recursion
        bool take = solve(nums, index+1, target - nums[index]);
        bool skip = solve(nums, index+1, target); //skipped the previous one while moving ahead

        return memo[index][target] = (skip || take);

    }
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        for(int i=0; i < n; i++){
            sum += nums[i];
        }
 
        if(sum %2 != 0) return false; //means it cannot be divided into two equal sums
        int target = sum/2; 
        memo.assign(n, vector<int>(target+1, -1));
        //the case where my sum is even is where i recurse  

        bool ans = solve(nums, 0, target);

        return ans;
        
    }
};
