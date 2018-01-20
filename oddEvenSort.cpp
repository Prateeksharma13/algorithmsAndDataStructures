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
    ListNode* oddEvenList(ListNode* head) {
        ListNode* odd = NULL;
        ListNode* retOdd = NULL;
        ListNode* retEven = NULL;
        ListNode* even = NULL;
        while(head) {
            ListNode* newNode = new ListNode(head->val);
            if((head->val)%2 != 0) {
                if(odd != NULL) {
                    odd->next = newNode;
                    odd = odd->next;
                } else {
                    odd = newNode;
                    retOdd = odd;
                }
            }else {
                if(even != NULL) {
                    even->next = newNode;
                    even = even->next;
                } else {
                    even = newNode;
                    retEven = even;
                }
            }
            head = head->next;
        }
        if(odd) {
            odd->next = retEven;
        } else {
            retOdd = retEven;
        }
        return retOdd;
    }
};
