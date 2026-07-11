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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode*temp=head;
        int count=0;
        while(temp!=NULL){
            count++;
            temp=temp->next;
        }
        if (n == count) { 
            ListNode* newHead = head->next;
            delete head;
            return newHead;
        }
        int start=count-n-1;
        ListNode*prev=head;
        for(int i =0;i<start;i++){
            prev=prev->next;
        }
        temp = prev->next;
        prev->next = temp->next;
        delete temp;
        return head;
    }
};