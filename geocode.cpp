#include <iostream>
#include <vector>
using namespace std;

int main() {
    int geo;
    cin >> geo;
    
    if (geo >= -90 && geo <= 90) {
        vector<int> code;
        int lo = -90, hi = 90, mid;
        while (code.size() < 6) {
            mid = (lo + hi) / 2;
            if (geo < mid) {
                hi = mid;
                code.push_back(0);
            }
            if (geo >= mid) {
                lo = mid;
                code.push_back(1);
            }
        }
        
        for (int i = 0; i < code.size(); ++i)
            cout << code[i];
    }
    
    return 0;
}
