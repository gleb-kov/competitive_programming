#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <unordered_set>
#include <set>
#include <cmath>
#include <unordered_map>

using namespace std;

using ll = int64_t;

ll total = 0;

ll iter(ll s, ll end, bool m = true) {
    if (s == 1) return 0;
    if (2 * s - 1 <= end) {
        ll sub = iter(s / 2, end, m);
        ll cur = 2 * sub + s - 1;
        if (m) total += cur;
        return cur;
    } else {
        if (end >= s + s / 2) {
            ll sub = iter(s / 2, s - 1, false) + s / 2;
            ll p = iter(s / 2, end - s, false) + end - s - s / 2 + 1;
            if (m) total += sub + p;
            return sub + p;
        } else {
            ll p = iter(s / 2, end - s / 2, false) + end - s + 1;
            if (m) total += p;
            return p;
        }
    }
}

int main() {
    iter(9007199254740992, 10000000000000000);
    iter(9007199254740992 / 2, 10000000000000000);
    cout << total;
}