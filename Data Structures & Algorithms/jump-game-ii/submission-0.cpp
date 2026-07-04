class Solution {
public:
    int jump(vector<int>& nums) {
        //I've to traverse through this while keeping track of which is my best jump omw
        //I traverse keep track of current End, the per index traversal which allows me the max I can travel
        int currEnd = 0;
        int jump = 0;
        //and now the maximum i can reach standing from an index
        int maxReach = 0;
        for(int i=0; i< nums.size()-1; i++){
            maxReach = max(maxReach, i+nums[i]);
            if(i == currEnd && i < nums.size()-1){ //when I reach the end of my current allowed window
                jump++;
                currEnd = maxReach;
            }
        }
        return jump;
    }
};
