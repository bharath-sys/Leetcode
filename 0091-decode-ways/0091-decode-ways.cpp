class Solution {
public:
    int solve(string& s, int idx, vector<int>& dp) {
        if (idx >= s.length())
            return 1;
        if (dp[idx] != -1)
            return dp[idx];
        int ways = 0;
        for (int len = 1; len <= 2; len++) {
            if (idx + len <= s.length()) {
                string substring = s.substr(idx, len);
                if (substring[0] == '0')
                    break;
                int val = stoi(substring);
                if (val >= 1 && val <= 26) {
                    ways += solve(s, idx + len, dp);
                }
            }
        }
        return dp[idx] = ways;
    }

    int numDecodings(string s) {
        if (s.empty())
            return 0;
        vector<int> dp(s.length(), -1);
        return solve(s, 0, dp);
    }
};