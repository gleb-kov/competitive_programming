#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <set>
#include <queue>
#include <unordered_map>
#include <stack>
#include <array>
 
using namespace std;
 
int main() {
    string a, b;
    cin >> a >> b;
    vector<pair<size_t, size_t>> res;
 
    for (size_t i = 0; i < a.size(); i++) {
        if (a[i] == b[i]) continue;
        size_t r = i;
        while (a[r] != b[i]) r++;
        reverse(a.begin() + i, a.begin() + r + 1);
        res.emplace_back(i, r);
    }
 
    cout << res.size() << '\n';
    for (auto &t : res) {
        cout << t.first + 1 << " " << t.second + 1 << '\n';
    }
}

