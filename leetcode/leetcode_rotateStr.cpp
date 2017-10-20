#include <iostream>
#include <string>
using namespace std;

void reverse(string& str, int begin, int end)
{
    while (begin < end) {
        char tmp = str[begin];
        str[begin] = str[end];
        str[end] = tmp;

        ++begin;
        --end;
    }
}

string rotateStr(string& str, int offset)
{
    if (str.empty() || offset == 0)
        return str;

    offset %= str.size();

    int len = str.size();
    reverse(str, 0, len - offset - 1);
    reverse(str, len - offset, len - 1);
    reverse(str, 0, len - 1);

    return str;
}

int main()
{
    string str1;
    int off;
    cin >> str1 >> off;

    cout << rotateStr(str1, off);

    return 0;
}
