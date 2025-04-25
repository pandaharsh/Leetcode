int removeDuplicates(int* nums, int numsSize) {
    int i, c=1;
    
    for(i=0; i<numsSize; i++) {
        if(nums[i] != nums[c-1]) {
            nums[c] = nums[i];
            c++;
        }
    }   
        
    return c;
}