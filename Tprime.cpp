#include <iostream>
using namespace std;

bool isPrime(const int& n) {
    if (n == 2 || n == 3)
        return true;
    if (n == 1 || n % 2 == 0)
        return false;
    for (int i = 3; i * i <= n; i += 2)
        if (n % i == 0)
            return false;
    return true;
}

int nextPrime(int n) {
    if (n % 2 == 0)
        ++n;
    else
        n += 2;

    for (; !isPrime(n); n += 2)
        ;

    return n;
}

int main() {
    int sum;
    cin >> sum;
    
    int count = 0, i = 2;
    if (sum >= 3 && sum < 1000) {
        while (i <= (sum / 2) + 1) {
            if (isPrime(sum - i))
                ++count;

            i = nextPrime(i);
        }
    }
    
    cout << count;
}
