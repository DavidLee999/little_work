#include <set>
#include <vector>
#include <utility>
#include <algorithm>
#include <iostream>
using namespace std;

struct point
{
    int x;
    int y;

    explicit point(const int& xx, const int& yy) : x{ xx }, y{ yy } {}
};

struct line
{
    point lp;
    point rp;
    int type;

    explicit line(const point& p1, const point& p2, int tp) : lp { p1 }, rp { p2 }, type { tp } {};
};

bool compare(const line& a, const line& b)
{
    return a.lp.x  < b.lp.x;
}

bool operator< (const point& a, const point& b)
{
    return a.y < b.y;
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
                for (auto it = s.lower_bound(l.lp); it != s.end() && it->y < l.rp.y; ++it)
                {
                    cout << l.rp.x << " " << it->y << endl;
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
    int p1x, p1y, p2x, p2y;
    for (int i = 0; i < numOfLines; ++i)
    {
        cin >> p1x >> p1y >> p2x >> p2y;

        if (p1x == p2x) // vertical
        {
            if (p1y < p2y)
                lines.push_back(line{point{p1x, p1y}, point{p2x, p2y}, 0});
            else
                lines.push_back(line{point{p2x, p2y}, point{p1x, p1y}, 0});
        }
        else
        {
            lines.push_back(line{point{p1x, p1y}, point{p2x, p2y}, 1});
            lines.push_back(line{point{p2x, p2y}, point{p1x, p1y}, 2});
        }
    }

    sort(lines.begin(), lines.end(), compare);


    interset(lines);

    // point a = make_pair(1, 2);
    // point b = make_pair(2, 1);
    // cout << (a < b) << endl;

    return 0;
}
