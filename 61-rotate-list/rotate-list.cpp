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
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == nullptr || head->next == nullptr) return head;
        // Step1 -- Find the length of the linkedList
        ListNode* temp = head;
        int length = 1;
        while (temp->next != nullptr){
            temp = temp->next;
            length++;
        }
        
        // step2 Optimized k
        k = k % length;
        if (k == 0) return head;

        // Step 3: Find the new tail (length - k - 1)
        temp->next = head;
        temp = head;
        for(int i = 0; i < length - k - 1; i++){
            temp = temp->next;
        }

        head = temp->next;
        temp->next = nullptr;

        return head;
    }
};