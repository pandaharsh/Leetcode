class Solution {
public:
    bool isValid(string s) {
       if(s.size() %2 !=0) {
            return false;
       } 
        std :: stack<char> shbd;
       
       for(auto & p:s) {
            switch (p) {
                case '(':
                case '{':
                case '[':
                  shbd.push(p);
                break;
            
                case '}':
                if(shbd.empty() || shbd.top() != '{') {
                    return false;
                }
                shbd.pop();
                break;
            
                case ')':
                if(shbd.empty() || shbd.top() != '(') {
                    return false;
                }  
                shbd.pop();
                break;

                case ']':
                if(shbd.empty() || shbd.top() != '[') {
                    return false;
                }  
                shbd.pop();
                break;

                break;
            }
        }
        return shbd.size() ==0;
    }
};