class Solution {
public:
    int searchRow(vector<vector<int>>& matrix,int target){
        int l = 0;
        int r = matrix.size()-1;
        while(l<=r){
            int m = l+(r-l)/2;
            if(matrix[m][0] == target)return m;
            else if(matrix[m][0] > target){
                r = m-1;
            }
            else l=m+1;
        }
        return r;
    }
    int searchCol(vector<vector<int>>& matrix, int target, int row){
        int l = 0;
        int r = matrix[0].size()-1;
        while(l<=r){
            int m = l+(r-l)/2;
            if(matrix[row][m] == target)return m;
            else if(matrix[row][m] > target){
                r = m-1;
            }
            else l=m+1;
        }
        return -1;
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = searchRow(matrix,target);
        if(row<0)return false;
        int col = searchCol(matrix,target,row);
        return col!=-1;
    }
};