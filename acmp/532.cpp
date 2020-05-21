#include <iostream>
#include <vector>
#include <set>
using namespace std;
typedef long long int ll;
 
int main()
{
    ll n, m, p, a, b, c, d, f=1e9, l=1, t = 0, s=0;
    cin >> n >> m >> p;
    vector<vector<ll>> o(p), u(p);
    multiset<ll> e, w;
    for (int i = 0; i < n; i++) {
        cin >> a >> b >> c >> d;
        t += b*(d - c);
        if (a>b) {
            if (c - 1 < f) f = c - 1;;
            if (d-1 > l) l = d-1;
            //лучше сидеть
            o[c-1].push_back(a - b);
            u[d-1].push_back(a - b);
        }
    }
    for (; f <= l; f++) {
        vector<ll>::iterator r;
        //выходят
        for (r = u[f].begin(); r != u[f].end(); r++) {
            if (w.count(*r)) {
                w.erase(w.find(*r));
            }
            else if (e.count(*r)) {
                s -= *r;
                e.erase(e.find(*r));
                if (w.size()) {
                    s += *w.rbegin();
                    e.insert(*w.rbegin());
                    w.erase(--w.end());
                }
            }
        }
        //заходят
        for (r = o[f].begin(); r != o[f].end(); r++) {
            if (e.size() < m) {
                //есть свободные места
                e.insert(*r);
                s += *r;
            }
            else {
                if (*r > *e.begin()) {
                    s -= *e.begin();
                    s += *r;
                    w.insert(*e.begin());
                    e.erase(e.begin());
                    e.insert(*r);
                }
                else w.insert(*r);
            }
        }
 
        t += s;
    }
    cout << t;
    return 0;
}

