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

struct pairhash {
public:
    template<typename T, typename U>
    std::size_t operator()(const std::pair<T, U> &x) const {
        return std::hash<T>()(x.first) ^ std::hash<U>()(x.second);
    }
};

ll sol(ll query, vector<ll> const &sieve, unordered_map<pair<ll, ll>, ll, pairhash> const &occur) {
    ll ans = 0;
    while (query > 1 && sieve[query] != query) {
        ll d = sieve[query];
        ll t = 0;
        while (query % d == 0) {
            t++;
            query /= d;
        }
        auto it = occur.find({d, t});
        if (it == occur.end()) {
            throw std::runtime_error("FAI");
        }
        ll o = it->second;
        ans = max(ans, o);
    }
    if (query > 1) ans = max(ans, query);
    return ans;
}

int main() {
    const ll SIEVE_SIZE = (ll) 1e8 + 10;
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

    // cout << "SIEVE end\n";

    ll border = (ll) 1e8;

    unordered_map<pair<ll, ll>, ll, pairhash> occur{};
    unordered_map<ll, ll> cnt;

    for (ll i = 2; i <= 100000; i++) {
        // if (i % 10000 == 0) cout << i << '\n';
        ll c = i;
        while (c > 1) {
            ll d = sieve[c];
            ll e = cnt[d];
            cnt[d]++;
            occur[{d, e + 1}] = i;
            c /= d;
        }
    }

    // cout << "answering\n";

    ll ans = 0;
    for (ll i = 2; i <= border; i++) {
        // if (i % 100000 == 0) cout << i << '\n';
        ans += sol(i, sieve, occur);
    }
    cout << ans;
}

