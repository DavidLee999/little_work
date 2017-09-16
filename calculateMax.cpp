#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;
int calculateMax(vector<int> prices) 
{
    int length = prices.size();
    vector<int> diff (length);
    for (int i = 1; i < length; ++i)
    {
        diff[i - 1] = prices[i] - prices[i - 1];
    }
    
    diff[length - 1] = -1;

    vector<int> earned;
    int n = 0;
    for (int i = 0; i < diff.size(); ++i)
    {
        if (diff[i] >= 0) {
            n += diff[i];
        }
        else {
            if (n > 0)
            {
                earned.push_back(n);
                n = 0;
            }
            else
                continue;
        }
    }
    
    for (int i = 0; i < earned.size(); ++i)
        cout << earned[i] << " ";
    cout << endl;

    if (earned.empty())
        return 0;
    else if (earned.size() == 1)
        return earned[0];
    else if (earned.size() == 2)
        return earned[0] + earned[1];
    else
    {
        std::sort(earned.begin(), earned.end(), std::greater<int>());
        return earned[0] + earned[1];
    }
}

int main()
{
    vector<int> prices;
    int tmp;
    while (cin >> tmp) {
        prices.push_back(tmp);
    }

    cout << calculateMax(prices) << '\n';

    return 0;

}
