/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void deleteNode(ListNode* node) {
        if (node == nullptr || node->next == nullptr) return; // Edge case (though guaranteed)

    node->val = node->next->val; // Copy next node's value
    ListNode* temp = node->next; // Store next node
    node->next = node->next->next; // Skip the next node
    delete temp;
    }
};