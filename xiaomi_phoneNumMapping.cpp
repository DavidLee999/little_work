#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solver(string& input, const vector<int>& ref)
{
    // const char A = 'A';
    vector<int> radix (26, 0);

    for (int i = 0; i < input.length(); ++i)
        ++radix[input[i] - 'A'];
    
    vector<int> medium (10, 0);

    medium[0] = radix['Z' - 'A'];
    medium[2] = radix['W' - 'A'];
    medium[4] = radix['U' - 'A'];
    medium[6] = radix['X' - 'A'];
    medium[8] = radix['G' - 'A'];
    medium[1] = radix['O' - 'A'] - medium[0] - medium[2] - medium[4];
    medium[3] = radix['H' - 'A'] - medium[8];
    medium[5] = radix['F' - 'A'] - medium[4];
    medium[7] = radix['S' - 'A'] - medium[6];
    medium[9] = radix['I' - 'A'] = medium[6] - medium[8] - medium[5];

    vector<int> res;

    for (int i = 0; i < 10; ++i)
    {
        while (medium[i] > 0) {
            res.push_back(ref[i]);
            --medium[i];
        }
    }

    std::sort(res.begin(), res.end());

    return res;
}

int main()
{
    int lines;
    cin >> lines;

    vector<string> input (lines);
    string tmp;

    for (int i = 0; i < lines; ++i)
    {
        cin >> tmp;
        input[i] = tmp;
    }

    vector<int> ref { 2, 3, 4, 5, 6, 7, 8, 9, 0, 1 };

    for (int i = 0; i < lines; ++i)
    {
        vector<int> res = solver(input[i], ref);
        for (int i = 0; i < res.size(); ++i)
            cout << res[i];
        cout << "\n";
    }

    return 0;
}
