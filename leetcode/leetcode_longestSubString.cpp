#include <iostream>
#include <string>
using namespace std;


int longestSubString(const string& str1, const string& str2)
{
    if (str1.empty() || str2.empty())
        return 0;

    int longest = 0, tmp = 0;;
    string::size_type i, j;
    for (i = 0; i < str1.size(); ++i)
    {
        for (j = 0; j < str2.size(); ++j)
        {
            tmp = 0;
            while (i + tmp < str1.size() && j + tmp < str2.size() && str1[i + tmp] == str2[j + tmp])
                ++tmp;

            if (tmp > longest)
                longest = tmp;
        }
    }

    return longest;
}


int main()
{
    string str1, str2;
    cin >> str1 >> str2;

    cout << longestSubString(str1, str2);

    return 0;
}
