class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size()) return false;
        else{
            unordered_map<char, int> seen;
            seen.reserve(s.size());

            for(auto it : s){
                seen[it]++;
            }
 
            for(auto it : t){
                seen[it]--;
                if(seen[it] < 0) return false;
            }
        }
        return true;
    }
};
