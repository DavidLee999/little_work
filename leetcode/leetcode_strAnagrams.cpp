#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool anagrams(const string& str1, const string& str2)
{
    if (str1.empty() || str2.empty())
        return false;

    if (str1.size() != str2.size())
        return false;

    vector<int> test (256, 0);

    for (string::size_type i = 0; i < str1.size(); ++i)
    {
        ++test[str1[i]];
        --test[str2[i]];
    }

    for (int i = 0; i < 256; ++i)
        if (test[i] != 0)
            return false;

    return true;
}

int main()
{
    string str1, str2;
    cin >> str1 >> str2;

    cout << anagrams(str1, str2) << '\n';

    return 0;
}
