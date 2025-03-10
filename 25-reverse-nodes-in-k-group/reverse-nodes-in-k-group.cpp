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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (head == nullptr) return head;
        ListNode* temp = head;
        vector<int> arr;
        while(temp != nullptr){
            arr.push_back(temp->val);
            temp = temp->next;
        }
        for (int i = 0; i + k <= arr.size(); i += k){
            reverse(arr.begin() + i, arr.begin() + i + k);
        }
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