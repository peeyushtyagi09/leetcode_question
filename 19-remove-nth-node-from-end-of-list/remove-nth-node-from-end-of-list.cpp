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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
         if (head == nullptr) return nullptr;
         ListNode* temp = head; 
         int count = 0;
         while(temp != nullptr){
            count++;
            temp = temp->next;
         }
         if (n > count) return nullptr;
         int end = count - n;
         if (end == 0){
            ListNode* newHead = head->next;
            delete head;
            return newHead;
         }
         temp = head;
         while (end > 1){
            temp = temp->next;
            end--;
         }
         ListNode* nodeToRemove = temp->next;
         temp->next = temp->next->next;
         delete nodeToRemove;
         return head;
    }
};