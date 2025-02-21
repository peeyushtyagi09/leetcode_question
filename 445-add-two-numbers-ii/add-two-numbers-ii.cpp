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
private:
    ListNode* reverseList(ListNode* head){
        ListNode* temp = head;
        ListNode* prev = nullptr;
        while(temp != nullptr){
            ListNode* newNode = temp->next;
            temp->next = prev;
            prev = temp;
            temp = newNode;
        }
        return prev;
    }
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* num1 = reverseList(l1);
        ListNode* num2 = reverseList(l2);

        ListNode*dummy = new ListNode(0);
        ListNode* temp = dummy;
        int carry = 0;
        while(num1 || num2 || carry){
            int sum = carry;
            if (num1){
                sum += num1->val;
                num1 = num1->next;
            }
            if (num2){
                sum += num2->val;
                num2 = num2->next;
            }
            carry = sum/10;
            temp->next = new ListNode(sum % 10);
            temp = temp->next;
        }
        ListNode* result = reverseList(dummy->next);
        while(result && result->val == 0 && result->next){
            ListNode* toDelete = result;
            result = result->next;
            delete toDelete;
        }
        return result;
    }
};