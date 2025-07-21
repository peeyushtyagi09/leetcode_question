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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root) return nullptr;

        if(key < root->val){
            root->left = deleteNode(root->left, key);
        }else if (key > root->val){
            root->right = deleteNode(root->right, key);
        }
        else{
            if(!root->left){
                TreeNode* temp = root->right;
                delete root;
                return temp;
            }

            if(!root->right){
                TreeNode* temp = root->left;
                delete root;
                return temp;
            }

            TreeNode* minNode = find(root->right);
            root->val =  minNode->val;
            root->right = deleteNode(root->right, minNode->val);
        }
        return root;
    }
private:
    TreeNode* find(TreeNode* node){
        while(node && node->left){
            node = node->left;
        }
        return node;
    }
};