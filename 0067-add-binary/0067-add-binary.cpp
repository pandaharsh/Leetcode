class Solution {
public:
    string addBinary(string a, string b) {
        string result;
        int extra = 0;
        int x = a.length() -1;
        int y = b.length() -1;

        while(x>=0 || y>=0 || extra) {
            if(x>=0){
                extra += a[x--] - '0';
            }
            if(y>=0) {
                extra += b[y--] -'0';
            }
            result += extra % 2 +'0';
            extra /= 2;
        }
        reverse( begin(result), end(result));
        return result;
    }
};