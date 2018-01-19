/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        if(!head) return head;
        while(head && head->val == val) {
            head = head->next;
        }
        ListNode* backup = head;
        while(head && head->next) {
            if(head->next->val == val) {
                 if(head->next->next != NULL) {
                    head->next = head->next->next;
                 } else {
                    head->next = NULL;
                 }
            } else {
                head = head->next;
            }
            if(!head->next) return backup;
        }
        return backup;
    }
};
