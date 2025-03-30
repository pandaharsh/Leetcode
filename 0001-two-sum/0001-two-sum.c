/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target, int* returnSize){
    int x, value, y, *arr= malloc(2 * sizeof(int)); 
    *returnSize= 2;
    for (x=0; x< numsSize; x++) {
        
        value= target - nums[x];
        
        for(y=0; y< numsSize; y++) {
            
            if(x!= y && value == nums[y]) {
            
                arr[0]= y;
                arr[1]= x;
                return (arr);
                break;
            
            }
        }       
    }
    return (arr);
    free(0);
}