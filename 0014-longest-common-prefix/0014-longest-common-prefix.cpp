class Solution {
public:
    string longestCommonPrefix(vector<string>& s) {
        string t=s[0]; int i, l;
        for(i=1; i<s.size(); i++) {
            string st;
            l=0;
            while(t[l] == s[i][l] && l<t.size() && l<s[i].size()) {
                st += t[l++];
            }
            if(s.size() == 0) {
                return "";
            }
            t=st;
        }
        return t;
    }
};