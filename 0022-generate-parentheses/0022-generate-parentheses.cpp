class Solution {
public:
    void generate(int n, vector<string>& ans, int op, int cp, string curr) {
        if (op == n && cp == n) {
            ans.push_back(curr);
            return;
        }
        if (op < n) {
            generate(n, ans, op + 1, cp, curr + '(');
        }
        if (op > cp) {
            generate(n, ans, op, cp + 1, curr + ')');
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        generate(n, ans, 0, 0, "");
        return ans;
    }
};