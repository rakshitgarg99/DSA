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
        ListNode* turtle = head;
        ListNode* hare = head;
        ListNode* temp = head;
        
        while(hare!=NULL && hare->next!=NULL){
            turtle = turtle->next;
            hare = hare->next->next;
        }
        
        // reverse from turtle to end and then compare
        ListNode* P = NULL;
        ListNode* C = turtle;
        ListNode* N = turtle->next;
        
        while(C!=NULL){
            C->next = P;
            P = C;
            C = N;
            if(N!=NULL){
                N = N->next;
            }
        }
        turtle = P;
        
        while(turtle){
            if(turtle->val != temp->val){
                return false;
            }
            turtle = turtle->next;
            temp = temp->next;
        }
        return true;
    }
};