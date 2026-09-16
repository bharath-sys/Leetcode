class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        vector<int> ans;
        int up = 1;
        int i=0; int j=0;
        int m = mat.size();
        int n = mat[0].size();
        while(i<=m-1 && j<=n-1){
            if(up==1){
                while(i>=0 && j<n){
                    ans.push_back(mat[i][j]);
                    if(i>0 && j<n-1){
                        i-=1;j+=1;
                    }
                    else break;
                }
                if(j<n-1)j+=1;
                else i+=1;
                up=0;
            }
            else {
                while(i<m && j>=0){
                    ans.push_back(mat[i][j]);
                    if(i<m-1 && j>0){
                        i+=1;j-=1;
                    }
                    else break;
                }
                if(i<m-1)i+=1;
                else j+=1;
                up=1;
            }
        }
        return ans;
    }
};