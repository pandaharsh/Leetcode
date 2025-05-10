/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* swapPairs(struct ListNode* head) {
    if(!head || !head->next)
    return head;
    struct ListNode* ptr=head->next;
    head->next = head->next->next;
    ptr->next = head;
    head = ptr;
    head->next->next = swapPairs(head->next->next);
    return head;
}