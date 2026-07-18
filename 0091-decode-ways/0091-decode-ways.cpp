class Solution {
public:
    vector<int> dp;
    int solve(string s, int idx) {
        if (idx == s.length())
            return 1;
        if (s[idx] == '0')
            return 0;
        if (dp[idx] != -1)
            return dp[idx];
        // one char
        int ways = solve(s, idx + 1);
        // two char
        if (idx + 1 < s.length()) {
            string substr = s.substr(idx, 2);
            if (substr >= "10" && substr <= "26")
                ways += solve(s, idx + 2);
        }
        return dp[idx] = ways;
    }
    int numDecodings(string s) {
        int n = s.length();
        dp.resize(n + 1, 0);
        dp[n] = 1;
        dp[n - 1] = s[n - 1] == '0' ? 0 : 1;
        for (int i = n - 2; i >= 0; i--) {
            if (s[i] == '0') {
                dp[i] = 0;
                // continue;
            } else {
                // if single charected ...
                dp[i] = dp[i + 1];
                // considering two charecters ...
                if (i + 1 < n &&
                    (s[i] == '1' || (s[i] == '2' && s[i + 1] <= '6'))) {
                    dp[i] += dp[i + 2];
                }
            }
        }
        return dp[0];
    }
};