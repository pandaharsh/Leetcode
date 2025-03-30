bool check(char *str, int start, int end) {
    while(start < end)
    {
        if(str[start] != str[end]) 
        {
            return false;
        }    
        start++;
        end--;
    }
    return true;
}

char* longestPalindrome(char* s) {
    int len = strlen(s), max = 0, i, j;
    char *obj = malloc(len+1);
    if (!obj) {
        return NULL;
    }

    obj[0] = '\0';

    for(i=0; i<len; i++) 
    {
        for(j=i; j<len; j++) 
        {
            if(check(s, i, j)) 
            {
                int currlen = j-i+1;
                if(currlen > max) 
                {
                    max = currlen;
                    strncpy(obj, &s[i], currlen);
                    obj[currlen] = '\0';
                }
            }
        }
    }
    return obj;
}