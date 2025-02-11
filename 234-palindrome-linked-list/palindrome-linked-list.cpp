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
        // First we are doing with two stack Time complexity of this code is O(N)
        // if (head == nullptr) return false;
        // ListNode* temp = head;
        // stack<int> st1;
        // while (temp != nullptr){
        //     st1.push(temp->val);
        //     temp = temp->next;
        // }
        // stack<int> st2;
        // stack<int> tempst = st1;
        // while (!tempst.empty()){
        //     st2.push(tempst.top());
        //     tempst.pop();
        // }
        // while (!st1.empty() && !st2.empty()){
        //     if(st1.top() != st2.top()){
        //         return false;
        //     }
        //     st1.pop();
        //     st2.pop();
        // }
        // return true;
    
        // Now i am doing this code in single stack time complexity of this code is O(N)

        // if (head == nullptr) return false;
        // ListNode* temp = head;
        // stack<int> st1;
        // while (temp != nullptr){
        //     st1.push(temp->val);
        //     temp = temp->next;
        // }
        // temp = head;
        // while (!st1.empty() && temp != nullptr){
        //     if (st1.top() != temp->val){
        //         return false;
        //     }
        //     st1.pop();
        //     temp = temp->next;
        // }
        // return true;


        // This are the not the optimal version of the code  because the time complexity of the code is O(N) 
        // The time complexity of the optimal version is code is o(1)
        // Optimal Approach (O(n) Time, O(1) Space)
        // Find the middle of the linked list using the fast and slow pointer approach.
        // Reverse the second half of the linked list.
        // Compare the first and second halves node by node.
        // Restore the list (optional) and return the result.

        if(head ==  nullptr || head->next == nullptr) return true;

        // step1 Find the middle of the linked list using the fast and slow pointer approach
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast != nullptr && fast->next != nullptr){
            slow = slow->next;
            fast = fast->next->next;
        }
        // step 2 Reverse the secound half os the linked list 
        ListNode* curr = slow;
        ListNode* prev = nullptr;
        while(curr){
            ListNode* nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }
        // Step3 Compare the first and second halves node by node.;
        ListNode* first = head, *second = prev;
        while(second){
            if(first->val != second->val) return false;
                first = first->next;
                second = second->next;
        }
        return true;
    }
};