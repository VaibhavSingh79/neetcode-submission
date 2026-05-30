class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> window;
        int left = 0;
        int max_len = 0;
        for(int right=0; right < s.size(); right++){
            while(window.find(s[right]) != window.end()){
                window.erase(s[left]);
                left++; //sliding the window
            }

            //means I found smthng new
            window.insert(s[right]);
            max_len = max(max_len, right-left+1);
        }
        return max_len;
    }
};
