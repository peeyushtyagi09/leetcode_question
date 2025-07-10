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
    int findBottomLeftValue(TreeNode* root) {
        // vector<vector<int>> result;
        // if(root == nullptr) return 0;
        // queue<TreeNode*> q;
        // q.push(root);
        // int n = 0;
        // while(!q.empty()){
        //     int size = q.size();
        //     vector<int> level;
        //     for (int i = 0; i < size; i++){
        //         TreeNode*  current = q.front();
        //         q.pop();
        //         level.push_back(current->val);

        //         if(current->left != nullptr)q.push(current->left);
        //         if(current->right != nullptr) q.push(current->right);
        //     }
        //     result.push_back(level);
        //     n++;
        // }
        // int ans = 0;
        // ans = result[n-1][0];
        // return ans;

        // optimal solution of that code 
        queue<TreeNode*> q;
        q.push(root);
        int leftmost = root->val;

        while(!q.empty()){
            int size = q.size();

            // First node of the level is leftmost
            leftmost = q.front()->val;

            for (int i = 0; i < size; i++){
                TreeNode * curr = q.front();
                q.pop();

                if(curr->left) q.push(curr->left);
                if(curr->right) q.push(curr->right);
            }
        }
        return leftmost;
    }
};