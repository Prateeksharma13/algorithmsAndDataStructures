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
        
        //This if will run only for the first iteration
        if(first_min == -1) {
            first_min = root->val; // Assign the root as first_minimum
            int left = -1; // Initializing left value 
            int right = -1; // Initializing right value
            
            //Get the values of current left and right
            if(root->left) {
                left = root->left->val;
            }         
            if(root->right) {
                right = root->right->val;
            }
            
            //Find second minimum in case both the nodes are present
            if(left != -1 && right != -1) {
                if(root->left->val < root->right->val && root->left->val > root->val) {
                    second_min = root->left->val;
                } else if(root->left->val > root->right->val && root->right->val > root->val) {
                    second_min = root->right->val;
                } else {
                    if(left > root->val) {
                        second_min = left;
                    } else if(right > root->val) {
                        second_min = right;
                    } else {
                        second_min = -1;
                    }
                }
                //Finding second_min if only one of the nodes is the present 
            } else {
                if(left != -1) { //If left is absent
                    if(right > root->val) {
                        second_min = right;
                    } else if(left > root->val) { //If right is absent
                        second_min = left;
                    } else {
                        second_min = -1; //
                    }
                }
            }     
        } else if(root->val < second_min) {
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
        return second_min;
    }
};
