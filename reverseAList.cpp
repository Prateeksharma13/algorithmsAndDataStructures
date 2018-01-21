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
    ListNode* reverseList(ListNode* head) {
        ListNode* pointer = NULL;
        while(head) {
            ListNode* nextElement = head->next; //points to 2
            head->next = pointer; //1 points to null
            pointer = head; //pointer has 1
            head = nextElement; //head has 2
        }  
        return pointer;
    }
};
