int lengthOfLongestSubstring(char* s) {
    int chFreq[128] = {0};
    int len = strlen(s);
    int ptr1 = 0, maxlen = 0;

    for(int ptr2 = 0; ptr2 < len; ptr2++) {
        char currChar = s[ptr2];

        while(chFreq[currChar] == 1)
            chFreq[s[ptr1++]]--;

        chFreq[currChar]++;
        if(maxlen < (ptr2 - ptr1 + 1))
            maxlen = ptr2 - ptr1 + 1;
    }
    return maxlen;
}