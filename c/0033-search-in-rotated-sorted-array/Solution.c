int search(int* nums, int numsSize, int target) {
    int i=0, flag=0;
    if(nums[i] == target)
        return 0;
    if(numsSize == 2 && nums[i+1] == target)
        return 1;
    for(i; i<numsSize/2; i++){
        if(nums[i] == target){
            flag = 1;
            break;
        }
        else if(nums[numsSize-i-1] == target){
            flag = 2;
            break;
        }
    }
    if(flag == 0){
        if(nums[i] == target)
            return i;
        else
            return -1;
    }
    else if(flag ==1)
        return i;
    else
        return numsSize-i-1;
}