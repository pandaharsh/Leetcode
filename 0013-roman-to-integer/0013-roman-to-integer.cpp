class Solution {
public:
    int romanToInt(string s) {
    char ROMAN[] = {'M', 'D', 'C', 'L', 'X', 'V', 'I'};
    int INT[] = {1000, 500, 100, 50, 10, 5, 1};
    int sum = 0, Int, temp = 1000, i;

    for (i = 0;; i++)
    {
        if (s[i] != '\0') {
            for (int j = 0; j < 7; j++) {
                if (s[i] == ROMAN[j]) {
                    Int = INT[j];
                    break;
                }
            }
            if (Int > temp)
                sum += Int - temp * 2;
            else
                sum += Int;

            temp = Int;
        } 
        else { 
            break;
        }
    }
    
    return sum;
}
};