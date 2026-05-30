class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount+1, amount+1);

        dp[0] = 0; //no coins needed to make 0 amt
        for(int i=1; i <= amount; i++){
            for(int coin : coins){
                if(i-coin >= 0){ //some amount is left or maybe this amt completes it?
                    dp[i] = min(dp[i], dp[i-coin]+1); //dp[i-coin] -> how many coins it needed to complete remaining amt?
                }
            }
        }
        return dp[amount] > amount ? -1 : dp[amount];
    }
};
