#include <iostream>
#include <map>
#include <cmath>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;
typedef long long int ll;

/*
THIS CODE FOR PRECALC ANSWER
IT WORKS LESS THAN 1 MINUTE
*/

map<int, ll> cnt_div;

ll col_div(ll n) {
    if (cnt_div[n]) return cnt_div[n];
    int t = n;
    ll m = 0;
    for (int i = 2; i <= sqrtl((double) n); i++) {
        if (n % i == 0) {
            while (n % i == 0) {
                n /= i;
                m++;
            }
            break;
        }
    }
    if (n == t) cnt_div[n] = 2;
    else cnt_div[t] = col_div(n) * (m + 1);
    return cnt_div[t];
}

vector<int> primes = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47};

int main() {
    ll mrn = 0, fr;
    cnt_div[1] = 1;
    set<pair<ll, int>> wave;
    wave.insert({1, 0});
    while (!wave.empty()) {
        ll v = (*wave.begin()).first;
        int t = (*wave.begin()).second;
        wave.erase(wave.begin());
        fr = col_div(v);
        if (fr > mrn) {
            cout << v << " " << fr << endl;
            mrn = fr;
        }
        for (int i = 0; i <= min(t, (int) primes.size() - 1); i++) {
            if (1e18 / primes[i] >= v) {
                wave.insert({primes[i] * v, max(t, i + 1)});
            }
        }
    }
    return 0;
}
