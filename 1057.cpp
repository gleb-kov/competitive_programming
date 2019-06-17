#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <map>
#include <iomanip>
#include <queue>
#include <algorithm>
using namespace std;
typedef long long int ll;
typedef long double ld;

int k, del;

vector<vector<ll>> c_table;

ll get_answ(int n) {
	vector<int> b;
	ll res = 0;
	int mn= 0, cnt = 0, rn = n;
	while (rn) {
		b.push_back(rn % del);
		if (rn % del != 0) mn++;
		cnt++;
		rn /= del;
	}
	if (mn == k) res++;

	if (k > cnt) return 0;

	for (ll i = k; i < cnt; i++) res += c_table[i - 1][k - 1];
	//cout << "prec " << res << endl;
	b.erase(--b.end());
	cnt--;
	reverse(b.begin(), b.end());

	int cur = 1;

	for (int i = 0; i < cnt && cur <= k; i++) {
		if (b[i] > 0) {
			res += c_table[cnt - i - 1][k - cur];
			cur++;
		}
	}
	return res;
}

ll get_b(ll m, ll cur, int step, int col) {
	if (step == 10 || col >= k || cur > m) {
		if (cur <= m && col == k) return 1;
		return 0;
	}
	ll t = get_b(m, cur, step + 1, col) + get_b(m, cur + pow(10, step), step + 1, col + 1);
	return t;
}

int main()
{
	c_table.resize(32, vector<ll>(32, 0));
	c_table[0][0] = 1;
	for (int i = 1; i < 32; i++) {
		c_table[i][0] = 1;
		for (int j = 1; j < 32; j++) {
			c_table[i][j] = c_table[i - 1][j] + c_table[i - 1][j - 1];
		}
	}
	int a, b;
	cin >> a >> b >> k >> del;
	if (del != 10) {
		cout << get_answ(b) - get_answ(a - 1);
	}
	else {
		cout << get_b(b, 0, 0, 0)-get_b(a - 1, 0, 0, 0);
	}
}
