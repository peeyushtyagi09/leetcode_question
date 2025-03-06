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
    ListNode* sortList(ListNode* head) {
        if(head == nullptr) return head;
        vector<int> arr;
        ListNode* temp = head;
        while(temp != nullptr){
            arr.push_back(temp->val);
            temp  = temp->next;
        }
        sort(arr.begin(), arr.end()); 
        ListNode* newHead = new ListNode(arr[0]);
        ListNode* curr = newHead;
        int index = 1;
       for (int i = 1; i < arr.size(); i++) {
            curr->next = new ListNode(arr[i]);  // Create new node
            curr = curr->next;  // Move to next node
        }
        
        return newHead; 
    }
}; 