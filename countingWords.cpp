#include <iostream>
#include <string>
#include <hash_map>
#include <fstream>
#include <cctype>
#include <unordered_map>
#include <queue>
using namespace std;

int main(int argc, char** argv)
{
    char* fileAddress = nullptr;

    if (argc != 2)
        return -1;
    else
        fileAddress = *(argv + 1);

    ifstream fin;
    fin.open(fileAddress, ios_base::in);
    if (!fin)
    {
        cerr << "Cannot open file!\n";
        return -1;
    }

    string str;
    unordered_map<string, int> wordsCounter;

    while (!fin.eof()) {
        fin >> str;

        for (int i = 0; i < str.size(); ++i)
        {
            if (ispunct(str[i]) || isdigit(str[i]))
                str.erase(i);
        }

        if (str.empty())
            continue;

        ++wordsCounter[str];

    }

    cout << "The total number of words is " << wordsCounter.size() << '\n';

    priority_queue< pair<int, string>, vector< pair<int, string> >, greater< pair<int, string> > > pq;
    int n;
    
    cout << "Inter a interger: ";
    cin >> n;
    
    if (n > 0)
    {
        for (unordered_map<string, int>::const_iterator itr = wordsCounter.begin(); itr != wordsCounter.end(); ++itr )
        {
            pq.push(make_pair(itr->second, itr->first));

            if (pq.size() > n)
                pq.pop();
        }
    }

    cout << "The top " << n << "words:\n";
    for (int i = 0; i < n; ++i)
    {
        cout << pq.top().second << '\t' << "times: " << pq.top().first << '\t'
            << static_cast<double>(pq.top().first) / wordsCounter.size() << '\n';
        pq.pop();
    }
    cout << endl;

    return 0;
}
