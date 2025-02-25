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
    int getDecimalValue(ListNode* head) {
        if(head == nullptr) return 0;
        ListNode* temp = head;
        int count = -1;
        while(temp != nullptr){
            count++;
            temp = temp->next;
        }
        temp = head;
        int sum = 0;
        while(temp != nullptr){
            sum += (temp->val * (pow(2, count)));
            temp = temp->next;
            count--;
        }
        return sum;
    }
};