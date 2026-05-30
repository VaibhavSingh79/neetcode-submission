class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int index=0;
        for(int i=0; i < nums.size()-1; i++){
            if(i == nums.size()){
                break;
            }
            if(nums[i] == nums[i+1]){
                return true;
            }
        }
        return false;
    }
};