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
    void preOrder(TreeNode* root,int &k,int &ans){
        if(root->left)preOrder(root->left,k,ans);
        k-=1;
        if(k==0){ans = root->val;return;}
        if(root->right)preOrder(root->right,k,ans);
    }
    int kthSmallest(TreeNode* root, int k) {
        int ans = INT_MAX;
        preOrder(root,k,ans);
        return ans;
    }
};