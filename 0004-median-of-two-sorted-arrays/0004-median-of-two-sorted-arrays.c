double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    double s;
    int b, t[nums1Size+nums2Size], i=0, j=0, k=0, total = nums1Size + nums2Size;
    while((i<nums1Size) && (j<nums2Size)) {
        if(nums1[i] < nums2[j]) {
            t[k] = nums1[i];
            i++;
            k++;
        }
        else {
            t[k] = nums2[j];
            j++;
            k++;
        }
    }
    
    if(i == nums1Size) {
        while(j<nums2Size) {
            t[k] = nums2[j];
            j++;
            k++;
        }
    }

    if(j== nums2Size) {
        while(i<nums1Size) {
            t[k] = nums1[i];
            i++;
            k++;
        }
    }

    if(total%2 != 0) {
        b = t[total/2];
        s = (double)b;
        return s;
    }
    else {
        s = ((double)((t[total/2]) + (t[(total/2)-1])))/2;
        return s;
    }
}