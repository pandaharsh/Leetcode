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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* c=head;
        ListNode* p=new ListNode(1);
        ListNode* k=p;
        while(c) {
            while(c->next && c->val== c->next->val)
            c=c->next;
            //cout<<"f";
            p->next=c;
            p=p->next;
            c=c->next;
        }
        p->next=NULL;
        return k->next;
    }
};