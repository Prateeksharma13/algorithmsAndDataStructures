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
    
    bool checkSum(TreeNode* root, int target, int current) {
        if(root == NULL) return false;
        if(root != NULL && !root->right && !root->left) return current+ root->val == target;
        return checkSum(root->left, target, current+root->val) || checkSum(root->right, target, current+root->val);
    }
    
    bool hasPathSum(TreeNode* root, int sum) {
        if(root == NULL) return false; 
        return checkSum(root, sum, 0);
    }
};
