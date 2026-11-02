/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* merger(struct ListNode* lm, struct ListNode* l){
    struct ListNode* p1 = lm;
    struct ListNode* p2 = l;
    struct ListNode* head;
    struct ListNode* last;
    struct ListNode* dummy=(struct ListNode*)malloc(sizeof(struct ListNode)*1);
    dummy->next = NULL;
    head = dummy;
    last = dummy;
    while(p1 != NULL && p2 != NULL){
        if(p1->val < p2->val){
            last->next = p1;
            last = p1;
            p1 = p1->next;
            last->next = NULL;
        }
        else{
            last->next = p2;
            last = p2;
            p2 = p2->next;
            last->next = NULL;
        }
    }
    if(p1 != NULL){
        last->next = p1;
    }
    if(p2 != NULL){
        last->next = p2;
    }
    return head->next;
}

struct ListNode* mergeKLists(struct ListNode** lists, int listsSize) {
    if(listsSize == 0){
        return NULL;
    }
    struct ListNode*res = lists[0];
    for(int i=1; i<listsSize; i++){
        res = merger(res, lists[i]);
    }
    return res;
}