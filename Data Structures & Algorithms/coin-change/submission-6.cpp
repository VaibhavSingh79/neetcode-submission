class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount+1, 1e9);
        dp[0] = 0; //no coins req for 0 amt
        for(int amt=1; amt <= amount; amt++){
            for(int coin : coins){
                if(amt - coin >= 0){
                    dp[amt] = min(dp[amt], 1+dp[amt-coin]);
                }
            }
        }
        return dp[amount] >= 1e9 ? -1 : dp[amount];
    }
};
