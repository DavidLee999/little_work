#include <iostream>
#include <string>
using namespace std;

bool strCmp(const string& str1, const string& str2)
{
    if (str1.size() < str2.size())
        return false;

    int test[26] {0};

    for (string::size_type i = 0; i < str1.size(); ++i)
        ++test[str1[i] - 'A'];

    for (string::size_type i = 0; i < str2.size(); ++i)
        --test[str2[i] - 'A'];

    for (int i = 0; i < 26; ++i)
        if (test[i] < 0)
            return false;

    return true;
}

int main()
{
    string str1, str2;
    cin >> str1 >> str2;

    cout << strCmp(str1, str2) << '\n';

    return 0;
}
