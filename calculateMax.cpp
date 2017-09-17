#include <iostream>
#include <vector>
using namespace std;

int getMax(const vector<int>& prices, int start, int end)
{
    int MIN = prices[start];
    int MAX = 0;
    for (int i = start + 1; i <= end; ++i)
    {
        if (prices[i] < MIN)
            MIN = prices[i];
        else if (prices[i] - MIN > MAX)
            MAX = prices[i] - MIN;
    }

    return MAX;
}

int calculateMax(vector<int> prices) 
{
   int max = 0, tmp = 0;

   for (int i = 1; i < prices.size(); ++i)
   {
       tmp = getMax(prices, 0, i) + getMax(prices, i, prices.size() - 1);
       if (tmp > max)
           max = tmp;
   }

   return max;
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
