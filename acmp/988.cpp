#include <iostream>
#include <cstdio>
#include <vector>
#include <list>
#include <queue>
#include <algorithm>
#include <set>
#include <unordered_set>
#include <unordered_map>
 
using namespace std;
 
using ll = int64_t;
 
vector<ll> len;
 
ll line(ll n) {
    for (ll i = 0; i < 63; i++) {
        if (n <= len[i]) return i + 1;
    }
    return 63;
}
 
ll solve(ll k, ll p) {
    if (p <= 1) return 1;
    if (k <= len[p - 2]) return solve(k, p - 1);
    k -= len[p - 2];
    if (k == 1) return p;
    return solve(k - 1, p - 1);
}
 
int main() {
    len.resize(63);
    len[0] = 1;
    for (int i = 1; i < 63; i++) {
        len[i] = len[i - 1] * 2ll + 1ll;
        // cout << i << " " << len[i] << '\n';
    }
    ll t, k, p;
    cin >> t;
    for (ll i = 0; i < t; i++) {
        cin >> k >> p;
        ll e = line(k);
        // cout << k << " " << e << '\n';
        if (e > p) cout << "No solution\n";
        else cout << solve(k, e) << '\n';
    }
}

