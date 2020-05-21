#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <cmath>
#include <algorithm>
#include <string>
#include <map>
using namespace std;
typedef unsigned long long int ll;
 
vector<pair<int, string>> dp;
 
void build(int n) {
    int sum = 0, r = n;
    string a = "";
    while (n) {
        a += (char)('0' + n % 10);
        sum += n % 10;
        n /= 10;
    }
    reverse(a.begin(), a.end());
    dp[r] = { sum, a };
}
 
int main()
{
    int n, m;
    cin >> n >> m;
    if (n%m == 0) {
        cout << 0;
        return 0;
    }
    dp.resize(m);
    dp[0] = { 0, "0" };
    for (int i = 1; i < m; i++) build(i);
    queue<int> wave;
    for (int i = 1; i < m; i++) wave.push(i);
    while (!wave.empty()) {
        int v = wave.front();
        wave.pop();
        for (int i = 0; i <= 9; i++) {
            int to = (10 * v + i) % m;
            if (dp[to].first > dp[v].first + i) {
                dp[to] = dp[v];
                dp[to].first += i;
                dp[to].second += (char)('0' + i);
                wave.push(to);
            }
        }
    }
    n %= m;
    if (n == 0) n = m;
    cout << dp[m - n].second;
}

