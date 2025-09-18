/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
bool existsInArray(int* arr, int size, int value) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == value) {
            return true;
        }
    }
    return false;
}

int* intersection(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize) {
    int* arr=(int*)malloc(1000*(sizeof(int)));
    *returnSize=0;
    for(int i=0; i<nums2Size; i++){
        for(int j=0; j<nums1Size; j++){
            if(nums2[i]==nums1[j] && !existsInArray(arr, *returnSize, nums2[i])){
                arr[(*returnSize)++]=nums2[i];
            }
        }
    }
    return arr;
}