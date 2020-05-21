#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <map>
#include <iomanip>
#include <queue>
#include <algorithm>

using namespace std;
typedef long long int ll;
typedef long double ld;

int main() {
    int t;
    ll r, x1, y1, x, y, h, p1, p2;
    ll a, b, c;
    cin >> t;
    for (int i = 0; i < t; i++) {
        cin >> r >> x1 >> y1 >> x >> y;
        h = r * r;
        bool g = true;
        p1 = x1 * x1 + y1 * y1;
        p2 = y * y + x * x;
        if (2 * p1 < h || p1 > r * r) g = false;
        if (2 * p2 < h || p2 > r * r) g = false;
        if (!g) cout << "NO";
        else {
            bool res = false;
            vector<pair<ll, ll>> v(4);
            v[0] = {x1, y1};

            for (int i = 0; i < 4 && !res; i++) {
                if (i) v[i] = {0 - v[i - 1].second, v[i - 1].first};
                if (v[i].first == x && v[i].second == y) res = true;

                if (v[i].first != x && v[i].second != y) {
                    a = v[i].second - y;
                    b = x - v[i].first;
                    c = 0 - (a * x + b * y);
                    if (2 * c * c == r * r * (a * a + b * b)) res = true;
                }
            }

            if (res) cout << "YES";
            else cout << "NO";
        }
        cout << endl;
    }
    return 0;
}
