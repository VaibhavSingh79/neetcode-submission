class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.size();
        int m = t.size();

        if(n < m) return "";
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


/*
APPROACH: Sliding Window + Two Frequency Maps
- O(n + m) time | O(1) space (maps have at most 26 keys)

CORE IDEA:
  Expand right until all characters of t are satisfied (have == need),
  then shrink left to find the minimum valid window.
  have tracks how many unique chars are fully satisfied.

STEPS:
  1. Fill mp1 with frequencies of t. need = mp1.size()
  2. Expand right: add s[right] to mp2
     if mp1.count(s[right]) && mp2[s[right]] == mp1[s[right]] → have++
  3. While have == need (valid window):
     → update ans_len and ans_left if current window is smaller
     → if s[left] exists in mp1 and mp2[s[left]] == mp1[s[left]] → have--
     → mp2[s[left]]--, left++
  4. Return "" if no window found, else s.substr(ans_left, ans_len)

KEY DETAIL:
  Always check mp1.count() before comparing frequencies —
  characters not in t must never affect have.
*/