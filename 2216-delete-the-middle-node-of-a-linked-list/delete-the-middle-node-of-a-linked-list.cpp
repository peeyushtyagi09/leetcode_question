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
    ListNode* deleteMiddle(ListNode* head) {
        if (head == nullptr || head->next == nullptr) return nullptr;
        int count = 0;
        ListNode* temp = head;
        while (temp != nullptr){
            count++;
            temp = temp->next;
        }
        int mid = count/2;
        temp = head;
        while (mid > 1){
            temp = temp->next;
            mid--;
        } 
        ListNode* toDelete = temp->next;
        temp->next = temp->next->next;
        delete toDelete;
        return head;
    }
};