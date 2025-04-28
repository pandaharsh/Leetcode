int strStr(char* haystack, char* needle) {
    int i=0, j=0, count=0, store;
    int len1 = strlen(haystack);
    int len2 = strlen(needle);

    while(i<len1) {
        if(haystack[i] == needle[j]) {
            i++;
            j++;
            count ++;
            if(count==1) {
                store =i;
            }
            if(count == len2) {
                return i-len2;
            }
        }
        else if(count>0) {
            count=0;
            j=0;
            i=store;
        }
        else{
            i++;
        }
    } 
    return -1;
}