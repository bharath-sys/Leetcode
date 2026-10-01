class Solution {
public:
    vector<vector<vector<double>>> memo;
    bool isValid(int n, int r, int c) {
        if (r >= 0 && r < n && c >= 0 && c < n)
            return true;
        return false;
    };
    double solve(int n, int k, int r, int c, vector<pair<int, int>>& dirs) {
        if (!isValid(n, r, c))
            return 0.0;
        if (k == 0)
            return 1;
        if (memo[r][c][k] != -1.0)
            return memo[r][c][k];
        double all = 0.0;
        for (auto& [dx, dy] : dirs) {
            all += ((1.0 / 8.0) * solve(n, k - 1, r + dx, c + dy, dirs));
        }
        return memo[r][c][k] = all;
    };
    double knightProbability(int n, int k, int row, int column) {
        vector<pair<int, int>> dirs = {
            {2, 1},  {1, 2},  {1, -2},  {-2, 1},
            {-1, 2}, {2, -1}, {-2, -1}, {-1, -2},
        };
        memo = vector<vector<vector<double>>>(
            n, vector<vector<double>>(n, vector<double>(k + 1, -1.0)));
        return solve(n, k, row, column, dirs);
        return 0.0;
    }
};