#include <iostream>
#include <set>
#include <vector>
 
using namespace std;
int n, c, r, i = 2e5;
 
int main() {
    multiset<int> q;
    cin >> n;
    vector<int> o[i];
    while (cin >> n >> c) o[n].push_back(c);
    while (--i) {
        for (auto j : o[i]) q.insert(j);
        if (q.size()) {
            auto v = --q.end();
            r += *v, q.erase(v);
        }
    }
    cout << r;
}

