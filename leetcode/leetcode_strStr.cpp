#include <string>
#include <iostream>
using namespace std;

int strStr (const string& haystack, const string& needle)
{
    if (haystack.empty() && needle.empty())
        return 0;

    if (haystack.empty())
        return -1;
    if (needle.empty())
        return 0;

    if (haystack.size() < needle.size())
        return -1;

    for (int i = 0; i < haystack.size() - needle.size() + 1; ++i)
    {
        string::size_type j = 0;
        for (; j < needle.size(); ++j)
            if (haystack[i + j] != needle[j])
                break;
        
        if (j == needle.size())
            return i;
    }

    return -1;
}


int main()
{
    string haystack, needle;
    cin >> haystack >> needle;

    cout << strStr(haystack, needle) << '\n';
    
    return 0;
}
