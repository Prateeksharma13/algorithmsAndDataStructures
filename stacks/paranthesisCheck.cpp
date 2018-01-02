class Solution {
private:
    stack<char> par;
public:
    bool isValid(string s) {
        for(int i = 0; i < s.size(); i++) {
            if(s[i] == '{' || s[i] == '[' || s[i] == '(') {
                par.push(s[i]);
            } else {
                if(par.empty()) {
                    return false;
                } else {
                    char top = par.top();
                    par.pop();
                    if((s[i] == '}' && top == '{') || (s[i] == ']' && top == '[') || (s[i] == ')' && top == '(')) {
                        continue;
                    } else {
                        return false;
                    }
                }
            }
        }
        if(par.empty()) {
            return true;
        }
        return false;
    }
};
