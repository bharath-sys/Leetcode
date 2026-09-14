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
    vector<vector<int>> ans;
    vector<int> path;
    int target = 0;
    void solve(TreeNode* root, int currSum) {
        if (!root)
            return;
        if (root) {
            path.push_back(root->val);
            if (!root->left && !root->right && currSum+root->val == target) {
                ans.push_back(path);
            } else {
                solve(root->left, currSum+root->val);
                solve(root->right, currSum+root->val);
            }
            path.pop_back();
        }
        return;
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        target=targetSum;
        solve(root, 0);
        return ans;
    }
};