/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void preOrder(TreeNode* root,vector<int> &order){
        if(root->left)preOrder(root->left,order);
        order.push_back(root->val);
        if(root->right)preOrder(root->right,order);
    }
    int kthSmallest(TreeNode* root, int k) {
        vector<int> order;
        preOrder(root,order);
        return order[k-1];
    }
};