/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<int> nextLargerNodes(ListNode* head) {
        vector<int> ans;
        ListNode* slow = head;

        while (slow != nullptr) {
            ListNode* fast = slow->next;
            int nextGreater = 0;

            while (fast != nullptr) {
                if (fast->val > slow->val) {
                    nextGreater = fast->val;
                    break;  // Stop when the first greater node is found
                }
                fast = fast->next;
            }
            
            ans.push_back(nextGreater);
            slow = slow->next;
        }
        
        return ans;
    }
};