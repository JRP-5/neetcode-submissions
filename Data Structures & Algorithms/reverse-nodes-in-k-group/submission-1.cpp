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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(k==1) {
            return head;
        }
        ListNode* dumH = new ListNode(-1, head);
        ListNode* prev = dumH;
        ListNode* curr = head;
        ListNode* nxt = curr->next;
        
        ListNode* prevK = dumH;
        ListNode* firstK = curr;
        bool hasK = true;
        while(hasK) {
            ListNode* checker = prevK;
            int i = 0;
            for(; checker && i < k; i++){
                checker = checker->next;
            }
            if(!checker || i != k){
                // cout << "fail\n";
                break;
            }
            // cout << "pass\n";
            for(int i =1; curr && i < k; i++){
                prev = curr;
                curr = nxt;
                nxt = nxt->next;
                curr->next = prev;
            }
            prevK->next = curr;
            firstK->next = nxt;

            prevK = firstK;
            firstK = nxt;

            if(nxt && nxt->next){
                prev = curr;
                curr = nxt;
                nxt = nxt->next;
            }
        }

        return dumH->next;
    }
};
