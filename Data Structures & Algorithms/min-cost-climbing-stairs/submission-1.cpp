class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        int prev1 = 0; //I can come here for free -> index0
        int prev2 = 0; //I can come here for free -> index1

        for(int i=2; i <= n; i++){
            int prev1_cost = cost[i-1] + prev1;
            int prev2_cost = cost[i-2] + prev2;

            int curr_cost = min(prev1_cost, prev2_cost);

            prev2 = prev1;
            prev1 = curr_cost;
        }

        return prev1;

    }
};
