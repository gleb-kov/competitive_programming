#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <iomanip>

using namespace std;
typedef long long int ll;
typedef long double ld;

struct point {
    double x, y;
};

bool cmp(point a, point b) {
    return a.x < b.x || a.x == b.x && a.y < b.y;
}

bool cw(point a, point b, point c) {
    return a.x * (b.y - c.y) + b.x * (c.y - a.y) + c.x * (a.y - b.y) <= 0;
}

bool ccw(point a, point b, point c) {
    return a.x * (b.y - c.y) + b.x * (c.y - a.y) + c.x * (a.y - b.y) >= 0;
}

vector<point> a;

bool make_convex_hull() {
    bool e = false;
    for (int i = 2; i < a.size(); i++) {
        if (a[0].x * (a[1].y - a[i].y) + a[1].x * (a[i].y - a[0].y) + a[i].x * (a[0].y - a[1].y) != 0) e = true;
    }
    if (!e) return e;

    point p1 = a[0], p2 = a.back();
    vector<int> up = {0}, down = {0};
    for (int i = 1; i < a.size(); i++) {
        if (i == a.size() - 1 || cw(p1, a[i], p2)) {
            while (up.size() >= 2 && !cw(a[up[up.size() - 2]], a[up[up.size() - 1]], a[i])) up.pop_back();
            up.push_back(i);
        }
        if (i == a.size() - 1 || ccw(p1, a[i], p2)) {
            while (down.size() >= 2 && !ccw(a[down[down.size() - 2]], a[down[down.size() - 1]], a[i])) down.pop_back();
            down.push_back(i);
        }
    }

    //start erasing point in convex hull
    vector<int> elist = up;
    for (int i = 0; i < down.size(); i++) elist.push_back(down[i]);

    sort(elist.rbegin(), elist.rend());

    for (int i = 1; i < elist.size() - 1; i++) a.erase(a.begin() + elist[i]);

    return true;
}

int main() {
    int n, answ = 0;
    cin >> n;
    a.resize(n);
    for (int i = 0; i < n; i++) cin >> a[i].x >> a[i].y;

    sort(a.begin(), a.end(), cmp);
    bool e = true;
    while (a.size() > 2 && e) {
        e = make_convex_hull();
        if (!e) {
            cout << answ;
            return 0;
        }
        answ++;
    }
    cout << answ;
}
