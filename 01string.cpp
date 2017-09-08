#include <iostream>
#include <string>
using namespace std;

int main() {
    string str;
    cin >> str;
    
    if (str.size() >= 1) {
        int maxLength = 1, tmp = 1;
        for (int i = 1; i < str.size(); ++i) {
            if (str[i] != str[i - 1]) {
                ++tmp;
            }
            else {
                if (tmp >= maxLength) {
                    maxLength = tmp;
                    tmp = 1;
                }
            }
        }
        if (tmp > maxLength)
            maxLength = tmp;
        
        cout << maxLength;
    }
    else
        cout << 0;
    return 0;
}
