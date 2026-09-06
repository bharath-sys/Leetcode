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
        else memo[i][j] = max(solve(s,i+1,j),solve(s,i,j-1));
        return memo[i][j];
    }
    int longestPalindromeSubseq(string s) {
        // memo.resize(s.length(),vector<int> (s.length(),-1));
        memo.resize(s.length(),vector<int> (s.length(),0));
        for(int i=0;i<=s.length()-1;i++){
            for(int j=0;j<=s.length()-1;j++){
                if(j==i)memo[i][j] = 1;
            }
        }
        for(int i=s.length()-1;i>=0;i--){
            for(int j=i+1;j<s.length();j++){
                if(s[i]==s[j]){
                    memo[i][j] = 2+memo[i+1][j-1];
                }
                else {
                    memo[i][j] = max(memo[i+1][j],memo[i][j-1]);
                }
            }
        }
        return memo[0][s.length()-1];
    }
};