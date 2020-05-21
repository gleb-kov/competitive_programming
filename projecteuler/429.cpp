#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <unordered_set>
#include <set>
#include <cmath>
#include <unordered_map>

using namespace std;

using ll = uint64_t;

ll mod = 1e9 + 9;

ll mul(ll a, ll b) {
    return (a*b)%mod;
}

ll fast_pow(ll x, ll p) {
    ll res = 1;
    while (p) {
        if (p & 1) res = mul(res, x);
        x = mul(x, x);
        p /= 2;
    }
    return res;
}

int main() {
    // linear sieve + binpow + mul by mod
    const ll SIEVE_SIZE = 100000010;

    vector<ll> sieve(SIEVE_SIZE, 0);
    vector<ll> primes;

    for (ll d = 2; d < SIEVE_SIZE; d++) {
        if (sieve[d] == 0) {
            sieve[d] = d;
            primes.push_back(d);
        }
        for (ll j : primes) {
            if (j > sieve[d] || j * d >= SIEVE_SIZE) break;
            sieve[j * d] = j;
        }
    }

    vector<ll> factor(SIEVE_SIZE, 0);
    for (ll i = 2; i <= 100000000; i++) {
        ll n = i;
        while (n > 1) {
            ll d = sieve[n];
            factor[d]++;
            n /= d;
        }
    }
    ll res = 1;
    for (ll i = 2; i <= 100000000; i++) {
        // cout << i << ' ' << factor[i] << '\n';
        if (factor[i] == 0) continue;
        ll a = fast_pow(i, 2 * factor[i]);
        a = (1 + a) % mod;
        res = mul(res, a);
    }
    cout << res;
}