class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        while (head != NULL && head->val == val) {
            ListNode* temp2 = head;
            head = head->next;
            delete temp2;
        }
        if (head == NULL) return NULL;

        ListNode* temp = head;
        while (temp->next != NULL) {
            if (temp->next->val == val) {
                ListNode* temp2 = temp->next;
                temp->next = temp2->next;
                delete temp2;
            } else {
                temp = temp->next;
            }
        }
        return head;
    }
};