class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        if(n <= 1) return n;
        unordered_map<char, int> mp;
        int left = 0;
        int ans = 0;
        for(int right = 0; right < n; right++){
            mp[s[right]]++; //updating the map
            int max_freq = 0;
            int window_size = right-left+1;

            //finding current max frequency 
            for(auto &ele: mp){
                max_freq = max(max_freq, ele.second);
            }
            //validity check 
            if(window_size - max_freq > k){
                mp[s[left]]-- ;
                left ++;
            }
            else{
                ans = max(ans, window_size);
            }
        }
        return ans;
    }
};
