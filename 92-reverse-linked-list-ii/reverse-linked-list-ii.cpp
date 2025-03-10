/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x)9jk*, next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        // if(head == nullptr) return head;
        // ListNode* temp = head;
        // vector<int> arr;
        // while(temp != nullptr){
        //     arr.push_back(temp->val);
        //     temp = temp->next;
        // }
        // reverse(arr.begin() + left - 1, arr.begin() + right);
        // temp = head;
        // int index = 0;
        // while(temp != nullptr){
        //     temp->val = arr[index];
        //     temp = temp->next;
        //     index++;
        // }
        // return head;

        // Optimal solution of that code using(one-pass, In-place)
        if(!head || left == right) return head;
        ListNode dummy(0);
        dummy.next = head;
        ListNode* prev = &dummy;
        for (int i = 0; i < left - 1; i++){
            prev = prev->next;
        }
        ListNode* curr = prev->next;
        ListNode* nextNode = nullptr;
        for (int i = 0; i < right - left; i++){
            nextNode = curr->next;
            curr->next = nextNode->next;
            nextNode->next = prev->next;
            prev->next = nextNode;
        }
        return dummy.next;
    }
};