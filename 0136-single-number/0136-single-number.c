int singleNumber(int* nums, int numsSize) {
    int i, newnum = 0;
    for(i = 0; i < numsSize; i++) {
        newnum = newnum ^ nums[i]; 
    }
    return newnum;
}