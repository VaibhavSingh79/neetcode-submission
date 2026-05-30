class Solution {
public:
    vector<int> memo;
    int dfs(string &s, int index){
        if(index == s.size()) return 1;

        if(s[index] == '0') return 0;

        if(memo[index] != -1) return memo[index];

        int ways = dfs(s, index+1);
        //now all valid cases
        if(index + 1 < s.size()){
            if(stoi(s.substr(index,2)) <= 26){
                ways += dfs(s, index+2);
            }
        }
        return memo[index] = ways;
    }
    int numDecodings(string s) {
        int n = s.size();
        memo.assign(n, -1);
        return dfs(s, 0);
    }
};