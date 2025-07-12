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
    int widthOfBinaryTree(TreeNode* root) {
        if (!root) return 0;

        queue<pair<TreeNode*, unsigned long long>> q;
        q.push({root, 0});
        int maxWidth = 0;
        while(!q.empty()){
            int size = q.size();
            unsigned long long minIndex = q.front().second;
            unsigned long long first, last;

            for (int i = 0; i < size; ++i){
                auto [node, index] = q.front();
                q.pop();
                index -= minIndex;

                if (i == 0) first = index;
                if (i == size - 1) last = index;

                if (node->left) q.push({node->left, 2*index});
                if (node->right) q.push({node->right, 2 * index + 1});
            }

            maxWidth = max(maxWidth, (int)(last - first + 1));
        }
        return maxWidth;

    }
};