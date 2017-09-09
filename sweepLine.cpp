#include <set>
#include <vector>
#include <utility>
#include <algorithm>
#include <iostream>
using namespace std;

typedef pair<int, int> point;
#define x first;
#define y second;

struct line
{
    point lp;
    point rp;
    int type;

    explicit line(point p1, point p2, int tp) : lp { p1 }, rp { p2 }, type { tp } {};
};

bool compare(const line& a, const line& b)
{
    return a.lp.first  < b.lp.first;
}

bool operator< (const point& a, const point& b)
{
    return a.second < b.second;
}

void interset(const vector<line>& lines)
{
    set<point> s;
    for (int i = 0; i < lines.size(); ++i)
    {
        line l = lines[i];
        if (l.type == 1) // horizonal line. begin point
            s.insert(l.lp);
        else if (l.type == 2) // horizontal line, end point
            s.erase(l.rp);
        else // vertial line
        {
            if (s.empty())
                continue;
            else
            {
                for (auto it = s.lower_bound(l.lp); it != s.end() && it->second < l.rp.second; ++it)
                {
                    cout << l.rp.first << " " << it->second << endl;
                }
            }
        }
    }
}

int main()
{
    int numOfLines;
    cin >> numOfLines;
    vector<line> lines;
    for (int i = 0; i < numOfLines; ++i)
    {
        int p1x, p1y, p2x, p2y;
        cin >> p1x >> p1y >> p2x >> p2y;

        if (p1x == p2x) // vertical
        {
            if (p1y < p2y)
                lines.push_back(line{make_pair(p1x, p1y), make_pair(p2x, p2y), 0});
            else
                lines.push_back(line{make_pair(p2x, p2y), make_pair(p1x, p1y), 0});
        }
        else
        {
            lines.push_back(line{make_pair(p1x, p1y), make_pair(p2x, p2y), 1});
            lines.push_back(line{make_pair(p2x, p2y), make_pair(p1x, p1y), 2});
        }
    }

    sort(lines.begin(), lines.end(), compare);

    interset(lines);

    // point a = make_pair(1, 2);
    // point b = make_pair(2, 1);
    // cout << (a < b) << endl;

    return 0;
}
