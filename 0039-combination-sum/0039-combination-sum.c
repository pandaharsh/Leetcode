/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

void findSum(int *c , int n, int cidx, int target, int ** returnColoumnSize, int ** res, int* residx, int * buffer, int bidx) {
    if(!target) {
        int *temp = calloc(bidx, sizeof(int));
        memcpy(temp, buffer, bidx*sizeof(int));
        (*returnColoumnSize) [*residx] = bidx;
        res[*residx] = temp;
        (*residx) += 1;
        return;
    }
    if(target <= 0) return;
    for(int i = cidx; i<n; i++) {
        buffer[bidx] = c[i];
        findSum(c, n, i, target-c[i], returnColoumnSize, res, residx, buffer, bidx+1);
    }
}

int** combinationSum(int* candidates, int candidatesSize, int target, int* returnSize, int** returnColumnSize) {
    int **res = calloc(200, sizeof(int*));
    int buffer[1000];
    *returnColumnSize = (int*) calloc(1000, sizeof(int));
    *returnSize = 0;
    findSum(candidates, candidatesSize, 0, target, returnColumnSize, res, returnSize, buffer, 0);
    *returnColumnSize = realloc(*returnColumnSize, *returnSize * sizeof(int));
    return res;
}