#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

string s, t;
vector<int> z;

void z_function() {
    int n = s.length();
    for (int i = 1, l = 0, r = 0; i < n; ++i) {
        if (i <= r) {
            z[i] = min(r - i + 1, z[i - l]);
        }
        while (i + z[i] < n && s[z[i]] == s[i + z[i]]) {
            z[i]++;
        }

        if (i + z[i] > r + 1) {
            l = i;
            r = i + z[i] - 1;
        }
    }
}

int main() {
    int n, ans = -1;
    cin >> n >> s >> t;
    z.resize(3 * n + 1);

    s += '#' + t + t;

    z_function();

    for (int i = n + 1; i <= 3 * n; i++) {
        if (z[i] == n) {
            ans = i - n - 1;
            break;
        }
    }

    cout << ans << endl;
    return 0;
}