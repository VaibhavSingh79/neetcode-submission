class Solution {
public:
    int maxArea(vector<int>& heights) {
        int l = 0;
        int r = heights.size()-1;
        int max_water = 0;

        while(l < r){
            int width = r-l;

            int curr_water = width * min(heights[l], heights[r]);

            max_water = max(max_water, curr_water);

            if(heights[l] < heights[r]){
                l++;
            }else{
                r--;
            }
        }
        return max_water;
    }
};
