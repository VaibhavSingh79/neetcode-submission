class Solution {
public:
    vector<int> dp;
    int solve(vector<int> &coins, int amt){
        if(amt == 0) return 0;

        if(amt < 0) return 1e9;

        if(dp[amt] != -1) return dp[amt];

        //the case where amt > 0
        int minCoins = 1e9;
        for(int coin : coins){
            int curr_amt = amt - coin;
            int result = 1 + solve(coins, curr_amt);
            minCoins = min(minCoins, result);
        }
        return dp[amt] = minCoins;
    }
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        dp.assign(amount+1, -1);
        int ans = solve(coins, amount);
        return ans >= 1e9 ? -1 : ans;
    }
};