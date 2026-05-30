class Solution {
public:
    int lengthOfLongestSubstring(string s) {
       unordered_set<char> window;
       if(s.size()==1) return 1;
       int l = 0;
       int r = 0; 
       int size = 0;
       while(r < s.size()){
        if(window.count(s[r]) == 0){ //means it's not there
            window.insert(s[r]);
            size = max(size, r-l+1);
            r++;
        }
        else{ //means it exists
            window.erase(s[l]);
            l++;
        }
       }
       return size;
    }
};
