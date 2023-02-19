#include <iostream> 
#include <stack>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> t;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(' || s[i] == '[' || s[i] == '{') t.push(s[i]);
            else {
                if (t.empty()) return false;
                char top = t.top();
                if (s[i] == ')') {
                    if (top != '(') return false;
                }
                else if (s[i] == ']') {
                    if (top != '[') return false;
                }
                else if (s[i] == '}') {
                    if (top != '{') return false;
                }
                t.pop(); 
            }

        }
        if (!t.empty()) return false;
        return true;
    }
};