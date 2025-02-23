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
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head || !head->next) return head;
        
        // Dummy node to handle cases where head needs to be removed
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* prev = dummy;  // Points to the last node of result list
        ListNode* curr = head;   // Scans through the list
        
        while (curr && curr->next) {
            // Check if current node is the start of a duplicate sequence
            if (curr->val == curr->next->val) {
                // Skip all nodes with the same value
                while (curr->next && curr->val == curr->next->val) {
                    curr = curr->next;
                }
                // Move one more step to get past the last duplicate
                curr = curr->next;
                // Connect prev to the next unique node
                prev->next = curr;
            } else {
                // No duplicates, move both pointers forward
                prev = curr;
                curr = curr->next;
            }
        }
        
        // Store result and free dummy node
        ListNode* result = dummy->next;
        delete dummy;
        return result;
    }
};