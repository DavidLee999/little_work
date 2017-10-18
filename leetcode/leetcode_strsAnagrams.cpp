#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

bool anagrams(const string& str1, const string& str2)
{
    if (str1.empty() || str2.empty())
        return false;

    if (str1.size() != str2.size())
        return false;

    vector<int> test (256, 0);

    for (string::size_type i = 0; i < str1.size(); ++i)
    {
        ++test[str1[i]];
        --test[str2[i]];
    }

    for (int i = 0; i < 256; ++i)
        if (test[i] != 0)
            return false;

    return true;
}

vector<string> strsAnagrams(const vector<string> strs)
{
    if (strs.size() < 2)
        return strs;

    vector<string> res;
    vector<bool> visited (strs.size(), false);

    for (int i = 0; i < strs.size(); ++i)
    {
        bool hasAna = false;
        for (int j = i + 1; j < strs.size(); ++j)
        {
            if (!visited[j] && anagrams(strs[i], strs[j]))
            {
                res.push_back(strs[j]);
                hasAna = true;
            }
        }

        if (!visited[i] && hasAna)
            res.push_back(strs[i]);
    }

    return res;
}


vector<string> strsAnagramsUsingSort(const vector<string> strs)
{
    unordered_map<string, int> test;
    for (int i = 0; i < strs.size(); ++i)
    {
        string tmp = strs[i];
        sort(tmp.begin(), tmp.end());
        
        ++test[tmp];
    }

    vector<string> res;
    for (int i = 0; i < strs.size(); ++i)
    {
        string tmp = strs[i];
        sort(tmp.begin(), tmp.end());

        if (test[tmp] > 1)
            res.push_back(tmp);
    }

    return res;
}



int main()
{
    vector<string> strs;
    string tmp;

    while (cin>>tmp)
        strs.push_back(tmp);

    vector<string> res = strsAnagramsUsingSort(strs);

    for (int i = 0; i < res.size(); ++i)
        cout << res[i] << '\t';
    cout << endl;
}
