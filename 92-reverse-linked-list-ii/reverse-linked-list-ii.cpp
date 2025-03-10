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
        if(head == nullptr) return head;
        ListNode* temp = head;
        vector<int> arr;
        while(temp != nullptr){
            arr.push_back(temp->val);
            temp = temp->next;
        }
        reverse(arr.begin() + left - 1, arr.begin() + right);
        temp = head;
        int index = 0;
        while(temp != nullptr){
            temp->val = arr[index];
            temp = temp->next;
            index++;
        }
        return head;
    }
};