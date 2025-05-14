/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct TreeNode* createNewNode(int val) {
    struct TreeNode * newNode = (struct TreeNode*) malloc(sizeof(struct TreeNode));
    newNode->val = val;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

struct TreeNode* res(int* nums, int l, int r) {
    if(l > r) 
        return NULL;
    int mid = l + (r - l) / 2;
    struct TreeNode* node = createNewNode(nums[mid]);
    node->left = res(nums, l, mid-1);
    node->right = res(nums, mid+1, r);
    return node;
}

struct TreeNode* sortedArrayToBST(int* nums, int numsSize) {
    return res(nums, 0, numsSize-1);
}