class Solution {
public:
    vector<int> memo;
    int solve(string& s, int idx, string currNum) {
        if (idx >= s.length())
            return 1;
        else if (memo[idx] != -1)
            return memo[idx];
        if(s[idx]=='0'){
            return 0;
        }
        int singleDigit =  solve(s, idx + 1, s.substr(idx,1));
        int doubleDigit = 0;
        if(idx<s.length()-1 && ((s[idx]=='1' && s[idx+1]<='9') || (s[idx]=='2' && s[idx+1]<='6'))) {
            doubleDigit = solve(s, idx + 2, s.substr(idx, 2));
        }
        return memo[idx] = singleDigit + doubleDigit;
    }
    int numDecodings(string s) {
        memo.resize(s.length(), -1);
        return solve(s, 0, "");
    }
};