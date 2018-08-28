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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> result;
        helper(root, result);
        return result;
    }
    
    void helper(TreeNode* root, vector<int> &result) {
        if(root == NULL) return;
        
        if(root->left) {
            helper(root->left, result);
        } 
        if(root->right) {
            helper(root->right, result);
        }
        result.push_back(root->val);
    }
};
