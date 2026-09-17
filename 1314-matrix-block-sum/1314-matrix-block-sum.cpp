class Solution {
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {
        int m = mat.size();
        int n = mat[0].size();
        vector<vector<int>> ans(m,vector<int> (n,0));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i>0){
                    mat[i][j]+=mat[i-1][j];
                }
                if(j>0){
                    mat[i][j]+=mat[i][j-1];
                }
                if(i>0 && j>0){
                    mat[i][j]-=mat[i-1][j-1];
                }
            }
        }

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                int x1,y1,x2,y2;
                x1 = max(i-k,0);y1 = max(j-k,0);
                x2 = min(i+k,m-1);y2 = min(j+k,n-1);
                int total = mat[x2][y2];
                int top = x1>0 ? mat[x1-1][y2] : 0;
                int left = y1>0 ? mat[x2][y1-1] : 0;
                int topleft = x1>0 && y1>0 ? mat[x1-1][y1-1] : 0;
                ans[i][j] = mat[x2][y2]-top-left+topleft;
            }
        }
        
        return ans;
    }
};