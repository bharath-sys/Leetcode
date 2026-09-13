class Solution {
public:
    vector<int> row,col,diagnol,antiDiagnol;
    void solve(vector<vector<string>> &ans,vector<string> &board,int j,int n){
        if(n==0){
            ans.push_back(board);
            return;
        }
        if(j>=board.size())return;
        for(int i=0;i<board.size();i++){
            if(!row[i] && !col[j] && !diagnol[i+j] && !antiDiagnol[i-j+board.size()-1]){
                row[i] = col[j] = diagnol[i+j] = antiDiagnol[i-j+board.size()-1] = 1;
                board[i][j] = 'Q';
                solve(ans,board,j+1,n-1);
                board[i][j] = '.';
                row[i] = col[j] = diagnol[i+j] = antiDiagnol[i-j+board.size()-1] = 0;
            }
        }
        return;
    }
    vector<vector<string>> solveNQueens(int n) {
        row.resize(n,0);
        col.resize(n,0);
        diagnol.resize(2*(n+1),0);
        antiDiagnol.resize(2*(n+1),0);

        vector<string> board;
        for(int i=0;i<n;i++){
            string s;
            for(int j=0;j<n;j++){
                s.push_back('.');
            }
            board.push_back(s);
        }
        vector<vector<string>> ans;
        solve(ans,board,0,n);
        return ans;
    }
};