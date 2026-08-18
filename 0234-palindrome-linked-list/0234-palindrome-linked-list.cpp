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
        ListNode*temp=NULL;
        while(fast!=NULL&&fast->next!=NULL){
            fast=fast->next->next;
            temp=slow->next;
            slow->next=prev;
            prev=slow;
            slow=temp;
        }
        if(fast!=nullptr){
            slow=slow->next;
        }
        while(prev!=NULL&&slow!=NULL){
            if(prev->val!=slow->val){
                return false;
            }
            slow=slow->next;
            prev=prev->next;
        }
        return true;
    }
};