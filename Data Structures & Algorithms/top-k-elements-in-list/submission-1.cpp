class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // sort(nums.begin(), nums.end());
        unordered_map<int, int> freq;
        for(int i=0; i < nums.size(); i++){
            freq[nums[i]]++;
        }
        //now put this into a max heap and get the top k elements 
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> min_pq;

        for(auto it : freq){
            //it.first -> the number 
            //it.second -> the frequency of number
            min_pq.push({it.second, it.first});

            //keep a check if heap doesn't get much big than required
            if(min_pq.size() > k){
                min_pq.pop();
            }
        }

        vector<int> ans;
        while(!min_pq.empty()){
            auto it = min_pq.top().second;
            ans.push_back(it);
            min_pq.pop();
        }

        return ans;
    }
};
