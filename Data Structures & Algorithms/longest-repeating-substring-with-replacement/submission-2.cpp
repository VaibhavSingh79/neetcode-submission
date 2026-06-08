class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        if(n <= 1) return n;
        unordered_map<char, int> mp;
        int left = 0;
        int ans = 0;
        int max_freq = 0;
        for(int right = 0; right < n; right++){
            mp[s[right]]++; //updating the map
            int window_size = right-left+1;

            //finding current max frequency 
            max_freq = max(max_freq, mp[s[right]]);
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

/*
APPROACH: Sliding Window + Frequency Map
- O(n) time | O(1) space (map has at most 26 keys)

CORE IDEA:
  For any window, replacements needed = window_size - max_freq
  If replacements needed <= k → window is valid, expand right
  If replacements needed > k  → shrink from left

STEPS:
  1. Expand right every iteration, update frequency map
  2. Track max_freq as a running variable (only updates on add)
  3. If window invalid → decrement left char frequency, move left
  4. If window valid → update ans with current window size

KEY INSIGHT:
  We never need to shrink by more than 1 per step — if a larger
  window wasn't valid, a same-sized one won't be either.
  max_freq doesn't need to be recalculated on shrink —
  a stale value only makes the condition more conservative, never wrong.

PATTERN: Variable sliding window
*/
