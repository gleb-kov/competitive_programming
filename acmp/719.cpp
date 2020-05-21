#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
 
string s;
int q = 1e9+7, w = q+2, e = 1, y = 1,i=1;
 
int h(int m) {
    int p = 1, r = 0;
    for (auto t : s) {
        r = (r + 1LL * (t - '0') * p) % m;
        p = 1LL * p * 10 % m;
    }
    return r;
}
 
int main() {
    cin >> s;
    reverse(s.begin(), s.end());
    int v = h(q), b = h(w);
    for (; i <= 1e5; i++) {
        e = 1LL * e * i % q;
        y = 1LL * y * i % w;
        if (e == v && y == b) cout << i;
    }
}

