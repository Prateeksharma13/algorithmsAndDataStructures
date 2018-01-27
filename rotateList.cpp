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
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head) return head;
        ListNode* tail;
        ListNode* newNode;
        tail = newNode = head;
        int len = 1;
        while(tail && tail->next) {
            tail=tail->next;
            len += 1;
        }
        tail->next = head;
        for(int i=0; i<len-(k%len); i++) {
            tail = tail->next;
        }
        newNode = tail->next;
        tail->next = NULL;
        //if(k%len == 0) return head;
        return newNode;
    }
};
