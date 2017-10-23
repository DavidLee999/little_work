#include <iostream>
#include <string>
#include <cctype>
using namespace std;

void spaceRp(string& strIn, int trueLen)
{
    int len = 0;
    for (int i = 0; i < trueLen; ++i)
        if (isspace(strIn[i]))
            ++len;

    int newLen = trueLen + 2 * len;
    for (int i = trueLen - 1; i >= 0; --i)
    {
        if (!isspace(strIn[i]))
            strIn[--newLen] = strIn[i];
        else
        {
            strIn[--newLen] = '0';
            strIn[--newLen] = '2';
            strIn[--newLen] = '%';
        }
    }
}

int main()
{
    int trueLen;
    string strIn;
    getline(cin, strIn);
    cin >> trueLen;

    spaceRp(strIn, trueLen);

    cout << strIn;

    return 0;
}
