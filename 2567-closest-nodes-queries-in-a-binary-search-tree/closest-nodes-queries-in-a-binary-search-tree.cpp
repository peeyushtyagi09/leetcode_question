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
void inorder(TreeNode* root, vector<int>& sorted){
    if (root == nullptr) return;
    inorder(root->left, sorted);
    sorted.push_back(root->val);
    inorder(root->right, sorted);
}
    vector<vector<int>> closestNodes(TreeNode* root, vector<int>& queries) {
        vector<int> sorted;
        inorder(root, sorted);

        vector<vector<int>>ans;
        for (int q : queries){
            int floor = -1, ceil = -1;

            
            int low = 0, high = sorted.size() - 1;
            while(low <= high){
                int mid = low + (high - low) / 2;
                if (sorted[mid] <= q){
                    floor = sorted[mid];
                    low = mid + 1;
                }else{
                    high = mid - 1;
                }
            }
            low = 0, high = sorted.size() - 1;
            while (low <= high){
                int mid = low + (high - low) / 2;
                if (sorted[mid] >= q){
                    ceil = sorted[mid];
                    high = mid - 1;
                }else{
                    low = mid + 1;
                }
            }
            ans.push_back({floor, ceil});
        }
        return ans;
    }
};