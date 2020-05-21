#include <iostream>
#include <map>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long int ll;

int s, minres;
map<int, bool> was;
vector<int> ans, curans;
map<int, int> col;

void tryna(int cur, int step) {
    if (step < minres && cur >= 1) {
        if (s >= cur) {
            if (s - cur + step < minres) {
                minres = s - cur + step;
                ans = curans;
            }
        }

        if (cur > s) {
            curans.push_back(-1);
            for (int i = sqrt((double) cur); i >= 1; i--) {
                if (cur % i) continue;
                if (!was[i] || col[i] > step) {
                    curans.back() = i;
                    was[i] = true;
                    col[i] = step;
                    tryna(i, step);
                }
                if (i != 1 && (!was[cur / i] || col[cur / i] > step)) {
                    curans.back() = cur / i;
                    was[cur / i] = true;
                    col[cur / i] = step;
                    tryna(cur / i, step);
                }
            }

            for (int i = 1; i <= 4; i++) {
                if (!was[cur + i] || col[cur + i] > step + i) {
                    curans.back() = cur + i;
                    col[cur + i] = step + i;
                    was[cur + i] = true;
                    tryna(cur + i, step + i);
                }
                if (!was[cur - i] || col[cur - i] > step + i) {
                    curans.back() = cur - i;
                    col[cur - i] = step + i;
                    was[cur - i] = true;
                    tryna(cur - i, step + i);
                }
            }
            curans.erase(--curans.end());
        }
    }
}

int main() {
    int t;
    cin >> s >> t;
    if (s >= t) {
        cout << s - t << endl;
        if (s != t) cout << 2 << endl << s << " " << t;
        else cout << 1 << endl << s;
    } else {
        ans = {t};
        curans = {t};
        minres = min(t - s * (t / s), s * (t / s + 1) - t);
        if (minres != 0) {
            ans.push_back(s * (t / s));
            if (minres == s * (t / s + 1) - t) ans.back() = s * (t / s + 1);
        }
        was[t] = true;
        col[t] = 0;
        tryna(t, 0);
        if (ans.back() != s) ans.push_back(s);
        cout << minres << endl << ans.size() << endl;
        for (int i = ans.size() - 1; i >= 0; i--) cout << ans[i] << " ";
    }
    return 0;
}
