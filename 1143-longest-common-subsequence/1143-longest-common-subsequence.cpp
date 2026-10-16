class Solution {
public:
    vector<vector<int>> dp;
    int solve(string &s1, string &s2,int i,int j) {
        if(i>=s1.size() || j>=s2.size()) return 0;
        if(dp[i][j]!=-1)return dp[i][j];
        if(s1[i]==s2[j]){
            dp[i][j] = 1+solve(s1,s2,i+1,j+1);
        }
        else {
            int skipS1 = solve(s1,s2,i+1,j);
            int skipS2 = solve(s1,s2,i,j+1);
            dp[i][j] = max(dp[i][j],max(skipS1,skipS2));
        }
        return dp[i][j];
    }
    int longestCommonSubsequence(string text1, string text2) {
        if(text1.size()<text2.size())swap(text1,text2);
        dp.resize(text1.size()+1,vector<int>(text2.size()+1,-1));
        return solve(text1,text2,0,0);
    }
};