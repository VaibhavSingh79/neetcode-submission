class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.size();
        int m = t.size();

        unordered_map<char, int> mp1;
        unordered_map<char, int> mp2;

        //mp1 -> stores the keys to be checked
        //mp2 -> variable window size
        
        //filling the freq map
        for(int i=0; i < m; i++){
            mp1[t[i]]++;
        }

        int left = 0;
        int ans_len = 1e9;
        int ans_left = 0;
        int have = 0;
        int need = mp1.size();
        for(int right=0; right < n; right++){
            mp2[s[right]]++;
            if(mp1.count(s[right]) && mp2[s[right]] == mp1[s[right]]){
                have++;
            }

            while(have == need){
                if(right-left+1 < ans_len){
                    ans_len = right-left+1;
                    ans_left = left;
                }
                //decrement the have and move left only if it exists 
                if(mp1.count(s[left]) && mp2[s[left]] == mp1[s[left]]){
                    have--;
                }
                mp2[s[left]]--;
                left++;
            }
        }
        return ans_len == 1e9 ? "" : s.substr(ans_left, ans_len);
    }
};
