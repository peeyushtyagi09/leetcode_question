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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        // if(root == nullptr){
        //     return new TreeNode(val);
        // }

        // if (val > root->val){
        //     root->right = insertIntoBST(root->right, val);
        // }else{
        //     root->left = insertIntoBST(root->left, val);
        // }
        // return root;

        TreeNode* newNode = new TreeNode(val);
        if(!root) return newNode;

        TreeNode* curr = root;

        while(true){
             if (val > curr->val){
                if(curr->right == nullptr){
                    curr->right = newNode;
                    break;
                }
                curr = curr->right;
             }else{
                if(curr->left == nullptr){
                    curr->left = newNode;
                    break;
                }
                curr = curr->left;
             }
        } 
        return root;
    }
};