class Solution {
public:
    void facti(vector<int> &nums, vector<vector<int>> &ans, vector<int> &temp,vector<int> &freq){
        if(temp.size() == nums.size()){
            ans.push_back(temp);
        }
        for(int i=0; i < nums.size(); i++){
            if(freq[i] == 0){
                temp.push_back(nums[i]);
                freq[i]=1;
                facti(nums, ans, temp, freq);
                freq[i]=0;
                temp.pop_back();
            }
            
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> temp;
        vector<vector<int>> ans;
        vector<int> freq(nums.size(),0);
        facti(nums, ans, temp, freq);
        return ans;
    }
};
