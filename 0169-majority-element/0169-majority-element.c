int majorityElement(int* nums, int numsSize) {
    int sol=nums[0], cnt = 1, i;
    for(i=1; i<numsSize; i++) 
    {
        if(sol == nums[i]) 
        {
            cnt++;
        }
        else 
        {
            cnt--;
        }
        if(cnt == 0) 
        {
            sol = nums[i];
            cnt = 1;
        }
    }
    return sol;
}