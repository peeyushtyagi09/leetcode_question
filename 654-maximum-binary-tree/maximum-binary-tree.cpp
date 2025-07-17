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
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        stack<TreeNode*> st;

        for (int num : nums){
            TreeNode* current = new TreeNode(num);

            while(!st.empty() && st.top()->val < num){
                current->left = st.top();
                st.pop();
            }

            if(!st.empty()){
                st.top()->right = current;
            }
            st.push(current);
        }

        while(st.size() > 1) st.pop();
        return st.top();
    }
};