#include <iostream>
#include <string>
#include <cctype>
using namespace std;


string reverseWords(const string& strIn)
{
    if (strIn.empty() || strIn.length() == 0)
        return strIn;

    string strOut, tmp;
    string::size_type i = strIn.length();
    while (i != 0) {
        while (!isspace(strIn[--i])) {
            tmp.push_back(strIn[i]);
            
            if (i == 0)
                break;
        }

        if (!tmp.empty())
        {
            if (!strOut.empty())
                strOut.push_back(' ');
            for (int j = tmp.size() - 1; j >= 0; --j)
                strOut.push_back(tmp[j]);
        }
        tmp.clear();
    }

    return strOut;
}


int main()
{
    string strIn;
    getline(cin, strIn);

    string strOut = reverseWords(strIn);

    cout << strOut;

    return 0;
}
