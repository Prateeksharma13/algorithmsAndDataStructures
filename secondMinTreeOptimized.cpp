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
    int first_min = -1; //Initial value of the smallest element
    int second_min = -1; //Initial value of the second smallest element
    int findSecondMinimumValue(TreeNode* root) {
        if(first_min == -1) {
            first_min = root->val;
            if(root->left) {
                if(root->val != root->left->val) {
                    second_min = root->left->val;
                } else {
                    if(root->right) {
                        second_min = root->right->val;
                    }
                }      
            }
        }
        
        if(root->val < second_min) {
            if(root->val < first_min) {
                second_min = first_min;
                first_min = root->val;   
            } else if(root->val < second_min && root->val > first_min){
                second_min = root->val;
            }
        }
        
        if(root->left) {
            findSecondMinimumValue(root->left);
        }
        if(root->right) {
            findSecondMinimumValue(root->right);
        }
        if(second_min != first_min) {
            return second_min;
        }
        return -1;
    }
};
