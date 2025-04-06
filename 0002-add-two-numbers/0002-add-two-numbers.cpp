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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head= new ListNode(0); 
        ListNode* tail= head;
        int extra = 0;
        while(l1 != nullptr || l2 != nullptr || extra != 0 ) {
            int a = (l1!= nullptr) ? l1->val:0;
            int b = (l2!= nullptr) ? l2->val:0;

            int sum = a+b + extra;
            int num = sum %10;
            extra = sum/10;

            ListNode* newnode = new ListNode(num);
            tail->next = newnode;
            tail = tail->next;

            l1 = (l1!= nullptr) ? l1->next : nullptr;
            l2 = (l2!= nullptr) ? l2->next : nullptr;
        }

        ListNode* result = head->next;
        delete head;
        return result;
    }
};