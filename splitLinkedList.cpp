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
    vector<ListNode*> splitListToParts(ListNode* root, int k) {
        int c=0;
        int cp=0;
        vector<ListNode*> res;
        ListNode* t = root;
        while(root != NULL) {
            c+=1;
            root = root->next;
        }
        int r = c%k;
        int newk = (c/k);
        ListNode* newstart = t;
        for(int i=0; i < k; i++) {
            cp = newk;
            ListNode* lastVisited = t; 
            while(cp > 0 && t) {
                lastVisited = t;
                t = t->next;
                cp--;
            }
            if(r>0 && t){
                lastVisited = t;
                t = t->next; 
                r -=1;
            }
            if(lastVisited) {
                lastVisited->next = NULL; 
                res.push_back(newstart);
                newstart = t;
            }
        }
        while(res.size() < k) {
            ListNode* t = NULL;
            res.push_back(t);
        }
        return res;
    }
};
