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
    ListNode* oddEvenList(ListNode* head) {
        // that is the Brute force solution of that question with (Extra space)

        // if (head == nullptr || head->next == nullptr) return head;
        // ListNode* oddHead = new ListNode(0), *odd = oddHead;
        // ListNode* evenHead = new ListNode(0), *even = evenHead;
        // ListNode* temp = head;
        // int index = 0;
        // while (temp != nullptr){
        //     if (index % 2 == 1){
        //         odd->next = temp;
        //         odd = odd->next;
        //     }else{
        //         even->next = temp;
        //         even = even->next;
        //     }
        //     temp = temp->next;
        //     index++;
        // }
        // odd->next = nullptr;
        // even->next = oddHead->next;
        // return evenHead->next;

        // but we have the optimal solution solution of that proble that have the time and space complexity of o(n)
        if(head == nullptr || head->next == nullptr) return head;
        ListNode* odd = head;
        ListNode* even = head->next;
        ListNode* headeven = even;

        while(even != nullptr && even->next != nullptr){
            odd->next = even->next;
            odd = odd->next;
            even->next = odd->next;
            even = even->next;
        }
        odd->next = headeven;
        return head;
    }
};