class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount+1, amount+1);
        dp[0] = 0; //no coins needed for 0 rupees
        for(int i=1; i <= amount; i++){
            for(int coin : coins){
                //dp[i-coin] -> how many coins needed for remaining amount
                if(i-coin >= 0) dp[i] = min(dp[i], 1+dp[i-coin]);
            }
        }
        return dp[amount] > amount? -1 : dp[amount];
    }
};
