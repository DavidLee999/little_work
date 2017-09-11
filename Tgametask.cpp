#include <iostream>
using namespace std;
 
int main() {
    int task1, task2;
    cin >> task1 >> task2;
     
    if (task1 < 1 || task1 > 1024 || task2 < 1 || task2 > 1024) {
        cout << -1;
        return 0;
    }
    
    unsigned int res = 0;
    
    res |= 1 << task1;
    
    if (res & (1 << task2))
        cout << 1;
    else
        cout << 0;

    return 0;
}
