class Solution {
public:
    vector<int> dp;
    int solve(string s,int idx){
        if(idx==s.length())return 1;
        if(s[idx]=='0')return 0;
        if(dp[idx]!=-1)return dp[idx];
        // one char 
        int ways = solve(s,idx+1);
        // two char
        if(idx+1<s.length()){
            string substr = s.substr(idx,2);
            if(substr>="10" && substr<="26")
                ways+=solve(s,idx+2);
        }
        return dp[idx]=ways;
    }
    int numDecodings(string s) {
        if(s[0]=='0')return 0;
        dp.resize(s.length(),-1);
        return solve(s,0);
    }
};