class Solution {
public:
    vector<vector<int>> dp;

    bool solve(string& s, int o, int idx) {
        if (o < 0)
            return false;
        if (idx == s.size())
            return o == 0;
        if (dp[idx][o] != -1)
            return dp[idx][o];
        bool answer = false;
        if (s[idx] == '(') {
            answer = solve(s, o + 1, idx + 1);
        } 
        else if (s[idx] == ')') {
            answer = solve(s, o - 1, idx + 1);
        } 
        else {
            answer = solve(s, o + 1, idx + 1);
            if (!answer)
                answer = solve(s, o - 1, idx + 1);
            if (!answer)
                answer = solve(s, o, idx + 1);
        }

        return dp[idx][o] = answer;
    }

    bool checkValidString(string s) {
        int n = s.size();
        dp.assign(n, vector<int>(n + 1, -1));
        return solve(s, 0, 0);
    }
};