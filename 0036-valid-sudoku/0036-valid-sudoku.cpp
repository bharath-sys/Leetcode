class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<vector<int>> Mcol(9, vector<int>(9));
        vector<vector<int>> Mrow(9, vector<int>(9));
        vector<vector<int>> Mgrid(9, vector<int>(9));
        for (int row = 0; row < 9; row++) {
            for (int col = 0; col < 9; col++) {
                if (board[row][col] == '.')
                    continue;
                int val = board[row][col] - '1';
                int grid = (col / 3) + (row / 3 * 3);
                if (Mcol[col][val] || Mrow[row][val] || Mgrid[grid][val]) {
                    return false;
                }
                Mcol[col][val] = 1;
                Mrow[row][val] = 1;
                Mgrid[grid][val] = 1;
            }
        }
        return true;
    }
};