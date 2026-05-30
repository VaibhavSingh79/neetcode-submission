class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int low = 1;
        int high = nums.size()-1;
        while(low < high){
            int mid = low + (high-low)/2;
            int cnt = 0;
            for(int num : nums){
                if(num <= mid){
                    cnt++;
                }
            }

            if(cnt > mid){
                high = mid;
            }
            else{
                low = mid+1;
            }
        }
        return high;
    }
};
