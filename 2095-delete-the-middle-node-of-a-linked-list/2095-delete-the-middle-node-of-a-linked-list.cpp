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
    ListNode* deleteMiddle(ListNode* head) {
        if (head == NULL || head->next == NULL){
        return NULL;
        }
        int count=0;
        ListNode*temp=head;
        while(temp!=NULL){
            count++;
            temp=temp->next;
        }
        temp=head;
        int mid=count/2;
        ListNode*prev=NULL;
        for(int i =0;i<mid;i++){
            if(i==0){
                prev=head;
            }
            else{
                prev=prev->next;
            }
            temp=temp->next;
        }
        prev->next=temp->next;
        return head;
    }
};