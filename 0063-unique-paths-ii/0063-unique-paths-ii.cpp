class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& og) {
        // vector<vector<int>> dp(og.size(),vector<int>(og[0].size(),0));
        if(og[0][0]==1)return 0;
        for (int row = 0; row < og.size(); row++) {
            for (int col = 0; col < og[0].size(); col++) {
                og[row][col] = og[row][col] == 1 ? -1 : 0;
            }
        }
        for (int i = 0; i < og[0].size(); i++) {
            og[0][i] = (og[0][i] == -1 || (i>0 && og[0][i-1]==-1)) ? -1 : 1;
        }
        for (int i = 0; i < og.size(); i++) {
            og[i][0] = (og[i][0] == -1 || (i>0 && og[i-1][0]==-1)) ? -1 : 1;
        }
        for (auto row : og) {
            for (auto val : row) {
                cout << val << " ";
            }
            cout << endl;
        }
        for (int row = 1; row < og.size(); row++) {
            for (int col = 1; col < og[0].size(); col++) {
                int prevRow = 0;
                int prevCol = 0;
                if (og[row][col] != -1) {
                    prevRow = og[row - 1][col] == -1 ? 0 : og[row - 1][col];
                    prevCol = og[row][col - 1] == -1 ? 0 : og[row][col - 1];
                    og[row][col] = prevRow + prevCol;
                }
            }
        }
        return og[og.size() - 1][og[0].size() - 1] == -1
                   ? 0
                   : og[og.size() - 1][og[0].size() - 1];
    }
};