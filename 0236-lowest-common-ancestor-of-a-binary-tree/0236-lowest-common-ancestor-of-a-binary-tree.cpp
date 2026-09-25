/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root || p == root || q == root)
            return root;
        auto l = lowestCommonAncestor(root->left, p, q);
        if ((p == root || p == l) && (l == q || root == q))
            return root;
        auto r = lowestCommonAncestor(root->right, p, q);
        if ((l == p || r == p || root == p) && (l == q || r == q || root == q))
            return root;
        return l ? l : r;
    }
};