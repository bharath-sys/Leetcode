class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> mat(n, vector<int>(n, 0));
        int counter = 1;
        int l, r, t, b;
        l = t = 0;
        b = r = n - 1;
        while (l <= r && t <= b) {
            // left -> right
            for (int i = l; i <= r; i++)
                mat[t][i] = counter++;
            t++;
            // top -> bottom
            for (int i = t; i <= b; i++)
                mat[i][r] = counter++;
            r--;
            // right -> left
            if (t <= b) {
                for (int i = r; i >= l; i--)
                    mat[b][i] = counter++;
                b--;
            }
            // bottom -> top
            if (l <= r) {
                for (int i = b; i >= t; i--)
                    mat[i][l] = counter++;
                l++;
            }
        }
        return mat;
    }
};