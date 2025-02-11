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
    bool isPalindrome(ListNode* head) {
        // First we are doing with two stack;
        if (head == nullptr) return false;
        ListNode* temp = head;
        stack<int> st1;
        while (temp != nullptr){
            st1.push(temp->val);
            temp = temp->next;
        }
        stack<int> st2;
        stack<int> tempst = st1;
        while (!tempst.empty()){
            st2.push(tempst.top());
            tempst.pop();
        }
        while (!st1.empty() && !st2.empty()){
            if(st1.top() != st2.top()){
                return false;
            }
            st1.pop();
            st2.pop();
        }
        return true;
    }
};