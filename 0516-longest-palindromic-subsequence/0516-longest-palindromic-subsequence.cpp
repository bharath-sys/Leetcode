class Solution {
public:
    vector<vector<int>> memo;
    int solve(string &s,int i,int j){
        if(i>j)return 0;
        if(i==j)return 1;
        if(memo[i][j]!=-1)return memo[i][j];
        // will write memo later
        // 1.  if both are equal
        if(s[i]==s[j]){
            memo[i][j] = 2+solve(s,i+1,j-1);
        }
        int either =  max(solve(s,i+1,j),solve(s,i,j-1));
        return memo[i][j] = max(memo[i][j],either);
    }
    int longestPalindromeSubseq(string s) {
        memo.resize(s.length(),vector<int> (s.length(),-1));
        return solve(s,0,s.length()-1);
    }
};