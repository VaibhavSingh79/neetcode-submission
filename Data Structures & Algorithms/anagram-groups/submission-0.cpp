class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;
        vector<vector<string>> ans;
        for(auto &ele:strs){
            string key = ele; //this way I access elements without ever changing them
            sort(key.begin(), key.end());

            mp[key].push_back(ele); //push the elements with the same key
        }

        for(auto &ele : mp){
            ans.push_back(ele.second);
        }

        return ans;
    }
};
