#include <iostream>
#include <string>
using namespace std;


bool isMatch(const string& str1, const string& str2)
{
    int i = 0, j = 0, star = -1;
    while(i < str1.size()) {
        if (j > str2.size())
            return false;
        if (str2[j] == '?' || str1[i] == str2[j])
        {
            ++i;
            ++j;
            star = -1;
            // continue;
        }

        if (str2[j] == '*')
        {
            star = ++j;
        }

        if (star != -1)
        {
            j = star;
            ++i;
        }

    }

    if (j >= str2.size())
        return true;
    else
    {
        while(str2[j] == '*' && j < str2.size())
            ++j;
        if (j == str2.size())
            return true;
        else
            return false;
    }
}

int main()
{
    string str1, str2;
    getline(cin, str1);
    getline(cin, str2);

    cout << isMatch(str1, str2) << '\n';

    return 0;
}
