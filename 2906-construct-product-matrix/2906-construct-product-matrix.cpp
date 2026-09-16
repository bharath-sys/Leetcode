class Solution {
public:
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> ans(m,vector<int>(n,1));
        int pre = 1; 
        int mod = 12345;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                ans[i][j]=pre;
                pre=(1LL*pre*grid[i][j])%mod;
            }
        }
        long suff = 1;
        for(int i=m-1;i>=0;i--){
            for(int j=n-1;j>=0;j--){
                ans[i][j] = (1LL*ans[i][j]*suff)%mod;
                suff=(1LL*suff*grid[i][j])%mod;
            }
        }

        return ans;
    }
};