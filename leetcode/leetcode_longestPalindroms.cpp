#include <iostream>
#include <string>
#include <cctype>
using namespace std;

bool isPalindromes(const string& strIn)
{
    int i = 0, j = strIn.length() - 1;
    while (i < j) {
        if (strIn[i] == strIn[j])
        {
            --j;
            ++i;
        }
        else
            return false;
    }

    return true;
}

string longestPalindromes(const string& strIn)
{
    if (strIn.empty())
        return strIn;

    int longest = 0, start = 0;
    for (int i = 0; i < strIn.size(); ++i)
    {
        for (int j = i + 1; j <= strIn.size(); ++j)
        {
            string subst = strIn.substr(i, j - i);
            if (isPalindromes(subst) && subst.size() > longest)
            {
                longest = j - i;
                start = i;
            }
        }
    }
    string strOut = strIn.substr(start, longest);
    
    return strOut;
}

string palindromes(const string& strIn, int i, int j)
{
    while (i >= 0 && j < strIn.size() && strIn[i] == strIn[j]) {
        --i;
        ++j;
    }

    return strIn.substr(i + 1, j - i - 1);
}

string longestPalindromes2(const string& strIn)
{
    if (strIn.empty())
        return strIn;

    string strOut;
    for (int i = 0; i < strIn.size(); ++i)
    {
        string tmp;
        tmp = palindromes(strIn, i, i);
        if (tmp.size() > strOut.size())
            strOut = tmp;

        tmp = palindromes(strIn, i, i + 1);
        if (tmp.size() > strOut.size())
            strOut = tmp;
    }

    return strOut;
}

int main()
{
    string strIn;
    getline(cin, strIn);

    string strOut = longestPalindromes2(strIn);
    cout << strOut;

    return 0;
}
