#include <stack>
#include <string>
using namespace std;

class Solution {
public:
    int evalRPN(vector<string> &tokens) {
        stack<int> number;
        for (string c : tokens){
            if (c == "+" || c == "-" || c == "*" || c == "/") {
                int i, j, r;
                j = number.top();
                number.pop();
                i = number.top();
                number.pop();
                
                switch(*c.c_str()) {
                    case '+': {
                        r = i + j;
                        break;
                    }
                    case '-': {
                        r = i - j;
                        break;
                    }
                    case '*': {
                        r = i * j;
                        break;
                    }
                    case '/': {
                        r = i / j;
                        break;
                    }
                }
                number.push(r);
            }
            else {
                int tmp = std::stoi(c);
                number.push(tmp);
            }
        }
        
        return number.top();
    }
};
