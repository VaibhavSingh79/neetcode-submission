class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> combination;
        vector<vector<int>> ans;
        sort(candidates.begin(), candidates.end());
        calci(candidates, combination, target,ans, 0, 0);
        return ans;
    }

    void calci(vector<int> &candidates, vector<int> &combination, int target,vector<vector<int>> &ans, int index, int sum){
        if(sum == target){
            ans.push_back(combination);
            return;
        }  
        // if(sum > target){
        //     return;
        // }
        for(int i=index; i < candidates.size(); i++){
            if(candidates[i]+sum > target){
                break;
            }
            combination.push_back(candidates[i]);
            // sum += candidates[i];
            
            
            calci(candidates, combination, target,ans, i, sum + candidates[i]);
            // sum -= candidates[i];
            combination.pop_back();
        }
    }
};