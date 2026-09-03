class Solution {
public:
    vector<vector<int>> memo;

    int coinChange(vector<int>& coins, int amount) {
        if (amount == 0)
            return 0;
        int n = coins.size();
        const int INF = 1e9;
        memo.resize(n + 1, vector<int>(amount + 1, INF));
        // target = 0 requires 0 coins
        for (int i = 0; i <= n; i++) {
            memo[i][0] = 0;
        }
        // Tabulation
        for (int i = n - 1; i >= 0; i--) {
            for (int target = 1; target <= amount; target++) {
                // Take
                int take = INF;
                if (target >= coins[i]) {
                    take = 1 + memo[i][target - coins[i]];
                }
                // Not take
                int notTake = memo[i + 1][target];
                memo[i][target] = min(take, notTake);
            }
        }
        return memo[0][amount] == INF ? -1 : memo[0][amount];
    }
};
