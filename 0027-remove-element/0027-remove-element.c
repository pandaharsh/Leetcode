int removeElement(int* nums, int numsSize ,int val){
    int i, count=0;
    for(i=0; i<numsSize; i++) {
        if(nums[i]==val) {
            count++;
        }
        else {
            nums[i-count]= nums[i];
        }
    }
    return (numsSize-count);
}