class Solution {
public:
//bottom up
    int numDecodings(string s) {
        int n = s.size();
        vector<int> dp(n+1, 0); //dp vector

        dp[n] = 1; //ending has one possibility

        for(int i = n-1; i >= 0; i--){
            if(s[i] == '0'){
                //nothng happens
                dp[i] = 0;
            }
            else{ //any other integer exists 
                dp[i] = dp[i+1];

                //possibility for two jumps 
                if(i + 1 < n){ //I can
                    if(stoi(s.substr(i,2)) <= 26 && stoi(s.substr(i,2)) >= 10){
                        dp[i] += dp[i+2];
                    }
                }
            }
        }
        return dp[0];
    }
};
