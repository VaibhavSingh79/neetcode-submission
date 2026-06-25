class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size();
        int m = text2.size();
        vector<vector<int>>dp(n+1, vector<int>(m+1, 0));

        //dp[n+1][m+1] alr set to 0 so no explicit need
        for(int i = n-1; i>=0; i--){
            for(int j=m-1; j>=0; j--){
                if(text1[i] == text2[j]){
                    dp[i][j] = 1+dp[i+1][j+1];
                }
                //if it doesn't match
                else{
                    dp[i][j] = max(dp[i+1][j], dp[i][j+1]);
                }
            }
        }
        return dp[0][0];

    }
};
