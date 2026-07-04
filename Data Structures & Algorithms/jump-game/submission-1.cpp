class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxRun = 0;
        for(int i=0; i < nums.size(); i++){
            if(i > maxRun) return false;
            maxRun = max(maxRun, i+nums[i]);

            if(maxRun >= nums.size()-1) return true;
        }

        return true;
    }
};
