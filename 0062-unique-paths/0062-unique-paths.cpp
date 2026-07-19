class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m,vector<int>(n,1));
        for(int row=1;row<m;row++){
            for(int col=0;col<n;col++){
                if(col>0)dp[row][col] = dp[row-1][col]+dp[row][col-1];
            }
        }
        return dp[m-1][n-1];
    }
};