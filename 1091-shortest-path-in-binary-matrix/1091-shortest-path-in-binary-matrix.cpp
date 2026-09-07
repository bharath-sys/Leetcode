class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        if (grid[0][0] == 1)
            return -1;
        int n = grid.size();
        vector<vector<int>> visited(n, vector<int>(n, -1));
        queue<pair<int, int>> q;
        vector<vector<int>> dir = {{0, 1}, {1, 0},   {-1, 0}, {0, -1},
                                   {1, 1}, {-1, -1}, {1, -1}, {-1, 1}};
        q.push({0, 0});
        visited[0][0] = 1;
        while (q.size()) {
            auto [x, y] = q.front();
            q.pop();
            if (x == n - 1 && y == n - 1)
                return visited[x][y];
            for (int i = 0; i < 8; i++) {
                int dx = x + dir[i][0];
                int dy = y + dir[i][1];
                if (dx >= 0 && dy >= 0 && dx <= n - 1 && dy <= n - 1 &&
                    visited[dx][dy] == -1 && grid[dx][dy] == 0) {
                    q.push({dx, dy});
                    visited[dx][dy] = visited[x][y]+1;
                }
            }
        }
        return -1;
    }
};