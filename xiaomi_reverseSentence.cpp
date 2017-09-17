#include <iostream>
#include <string>
#include <cstring>
#include <vector>
using namespace std;

int main()
{
    string str, tmp;
    while (cin >> tmp) {
        str.append(tmp);
        str.append(" ");
    }

    char* cstr = new char[str.length() + 1];
    std::strcpy(cstr, str.c_str());

    char* pch = strtok(cstr, " ");
    
    vector<string> res;
    while (pch != NULL) {
        string st { pch };
        res.push_back(st);
        pch = strtok(NULL, " ");
    }

    for (int i = res.size() - 1; i > 0; --i)
        cout << res[i] << " ";
    cout << res[0];

    delete[] cstr;

    return 0;
}
