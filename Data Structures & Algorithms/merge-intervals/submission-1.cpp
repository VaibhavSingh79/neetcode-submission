class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> merger;

        sort(intervals.begin(), intervals.end());
        for(const auto &interval : intervals){
            if(merger.empty()|| merger.back()[1] < interval[0]){ //means not merging?
                merger.push_back(interval);
            }else{ //ans found 
                merger.back()[1] = max(merger.back()[1], interval[1]); //whichever has greater ending time
            }
        }

        return merger;
    }
};
