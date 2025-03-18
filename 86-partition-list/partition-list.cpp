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
    ListNode* partition(ListNode* head, int x) {
        ListNode* lessDummy = new ListNode(0);   // Stores < x
    ListNode* greaterDummy = new ListNode(0); // Stores ≥ x
    
    // Pointers to build the partitions
    ListNode* less = lessDummy;
    ListNode* greater = greaterDummy;
    
    // Traverse the original list
    ListNode* curr = head;
    while (curr != NULL) {
        if (curr->val < x) {
            // Add to less list
            less->next = curr;
            less = less->next;
        } else {
            // Add to greater list
            greater->next = curr;
            greater = greater->next;
        }
        curr = curr->next;
    }
    
    // Terminate greater list to avoid cycle
    greater->next = NULL;
    
    // Merge less and greater lists
    less->next = greaterDummy->next;
    
    // Return the new head
    return lessDummy->next;
    }
};