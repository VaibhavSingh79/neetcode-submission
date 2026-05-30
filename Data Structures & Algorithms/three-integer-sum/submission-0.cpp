class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        int n = nums.size();
        for(int i=0; i < n-2; i++){

            //skipping the duplicate values
            if(i > 0 && nums[i] == nums[i-1]) continue;

            int left = i+1;
            int right = n-1;

            while(left < right){
                int curr_sum = nums[i] + nums[left] + nums[right];

                if(curr_sum == 0){
                    ans.push_back({nums[i], nums[left], nums[right]});

                    //skip duplicates for left pointer
                    while(left < right && nums[left] == nums[left+1]) left++;

                    //skip duplicates for the right pointer
                    while(right > left && nums[right] == nums[right-1]) right--;

                    //after a valid ans is found move both inwards
                    left++;
                    right -- ;
                }
                else if(curr_sum > 0){
                    right--;
                }else{
                    left++;

                }
            }
        }
        return ans;
    }
};
