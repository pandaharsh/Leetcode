bool isPalindrome(char* s) {
    int start =0 , end = strlen(s)-1;

    while(start<end) {
        if(!isalnum(s[start])) {
            start++;
            continue;
        }
        else if(!isalnum(s[end])) {
            end--;
            continue;
        }
        else if (tolower(s[start]) != tolower(s[end])) {
            return false;
        }
        else {
            start++;
            end--;
        }
    }
    return true;
}