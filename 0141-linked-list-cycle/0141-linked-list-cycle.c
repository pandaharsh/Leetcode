/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
bool hasCycle(struct ListNode *head) {
    struct ListNode *first= head, *last=head;
    while(last && last->next) {
        first = first->next;
        last = last->next->next;
        if(first == last) {
            return true;
        }
    }
    return false;
}    