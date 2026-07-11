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
        ListNode*slow=head;
        ListNode*fast=head;
        ListNode*prev=NULL;
        while(fast!=NULL&&fast->next!=NULL){
            fast=fast->next->next;
            ListNode*temp=slow->next;
            slow->next=prev;
            prev=slow;
            slow=temp;
        }
        if(fast!=NULL){
            slow=slow->next;
        }
        while(slow!=NULL && prev!=NULL){
            if(slow->val != prev->val){
                return false;
            }
            else{
                slow=slow->next;
                prev=prev->next;
            }
        }
        return true;
    }
};