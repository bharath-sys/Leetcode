class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& og) {
        int m = og.size();
        int n = og[0].size();
        vector<vector<long>> ways(m,vector<long> (n,0));
        ways[0][0] = og[0][0]==1 ? 0 : 1;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(og[i][j]==1){
                    og[i][j] = -1;
                }
            }
        }
        // filling top and left cells as 1
        for(int i=1;i<m;i++){
            ways[i][0] = ways[i-1][0] ? og[i][0]==0 : 0;
        }
        for(int j=1;j<n;j++){
            ways[0][j] = ways[0][j-1] ? og[0][j]==0 : 0;
        }

        // now processing from 1,1 cell 
         for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                if(og[i][j]==0){
                    ways[i][j] = ways[i-1][j]+ways[i][j-1];
                }
            }
        }

        

        return ways[m-1][n-1];


    }
};