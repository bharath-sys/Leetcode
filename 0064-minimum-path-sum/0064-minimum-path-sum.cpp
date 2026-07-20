class Solution {
public:
    int minPathSum(vector<vector<int>>& dp) {
        int m,n;
        m = dp.size();
        n = dp[0].size();
        for(int i=1;i<n;i++){
            dp[0][i]+=dp[0][i-1]; 
        }
        for(int j=1;j<m;j++){
            dp[j][0]+=dp[j-1][0]; 
        }
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                dp[i][j] += min(dp[i-1][j],dp[i][j-1]);
            }
        }
        return dp[m-1][n-1];
    }
};