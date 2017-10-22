#include <string>
#include <cctype>
#include <iostream>
using namespace std;

bool isPalindrome(const string& strIn)
{
    if (strIn.empty())
        return true;

    int i = 0, j = strIn.length() - 1;
    while (i < j) {
        if (!isalnum(strIn[i]))
        {
            ++i;
            continue;
        }

        if (!isalnum(strIn[j]))
        {
            --j;
            continue;
        }

        if (tolower(strIn[i]) == tolower(strIn[j]))
        {
            ++i;
            --j;
        }
        else
            return false;
    }

    return true;
}

int main()
{
    string strIn;
    getline(cin, strIn);

    cout << isPalindrome(strIn) << '\n';

    return 0;
}
