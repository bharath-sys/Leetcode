/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<string>> ans;
    int height(TreeNode* root) {
        if (!root)
            return 0;
        int l = height(root->left);
        int r = height(root->right);
        return 1 + max(l, r);
    }
    void solve(TreeNode* root, int row, int l, int r) {
        if (!root)
            return;
        int m = (l + r) / 2;
        ans[row][m] = to_string(root->val);
        solve(root->left, row + 1, l, m - 1);
        solve(root->right, row + 1, m + 1, r);
    }
    vector<vector<string>> printTree(TreeNode* root) {
        int h = height(root);
        int c = pow(2, h) - 1;
        ans.resize(h, vector<string>(c, ""));
        solve(root, 0, 0, c);
        return ans;
    }
};