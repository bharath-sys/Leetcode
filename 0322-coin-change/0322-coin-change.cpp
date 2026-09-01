class Solution {
public:
    vector<vector<int>> memo;
    int solve(vector<int>& coins, int target, int idx) {
        if (target == 0) {
            return 0;
        }
        if (idx >= coins.size())
            return 1e9;
        if (memo[idx][target] != -1)
            return memo[idx][target];
        int notTakeVal = solve(coins, target, idx + 1);
        int takeVal = 1e9;
        if (target >= coins[idx]) {
            takeVal = 1+solve(coins, target - coins[idx], idx);
        }
        return memo[idx][target] = min(notTakeVal,takeVal);
    }
    int coinChange(vector<int>& coins, int amount) {
        if (amount == 0)
            return 0;
        memo.resize(coins.size(), vector<int>(amount + 1, -1));
        int ans = solve(coins, amount, 0);
        return ans == 1e9 ? -1 : ans;
    }
};