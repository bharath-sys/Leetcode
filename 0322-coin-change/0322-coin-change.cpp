class Solution {
public:
    static bool comparator(int a, int b) { return a > b; }
    vector<vector<int>> memo;
    int solve(vector<int>& coins, int target, int idx) {
        if (idx >= coins.size())
            return 0;
        if (memo[idx][target] != -1)
            return memo[idx][target];
        if (target == 0) {
            return 1;
        }
        int takeVal = 0;
        if (target >= coins[idx]) {
            int take = solve(coins, target - coins[idx], idx);
            if(take){
                takeVal = memo[idx][target] = 1 + take;
            }
        }
        int notTakeVal = solve(coins, target, idx + 1);
        return memo[idx][target] = notTakeVal && takeVal ? min(notTakeVal,takeVal) : notTakeVal ? notTakeVal : takeVal;
    }
    int coinChange(vector<int>& coins, int amount) {
        // sort(coins.begin(), coins.end(), comparator);
        if (amount == 0)
            return 0;
        memo.resize(coins.size(), vector<int>(amount + 1, -1));
        return solve(coins, amount, 0)-1;
    }
};