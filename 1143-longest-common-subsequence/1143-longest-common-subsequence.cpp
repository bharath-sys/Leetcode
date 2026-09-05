class Solution {
public:
    vector<vector<int>> memo;
    int solve(string &s1,string &s2,int idx1,int idx2){
        if(idx1>=s1.length() || idx2>=s2.length())return 0;
        if(memo[idx1][idx2]!=-1)return memo[idx1][idx2];
        int len = max(solve(s1,s2,idx1+1,idx2),solve(s1,s2,idx1,idx2+1));
        if(s1[idx1]==s2[idx2]){
            len = 1+solve(s1,s2,idx1+1,idx2+1);
        }
        return memo[idx1][idx2] = max(memo[idx1][idx2],len);
    }
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.length();
        int n = text2.length();
        // memo idx,position
        memo.resize(m,vector<int>(n,-1));
        return solve(text1,text2,0,0);
    }
};