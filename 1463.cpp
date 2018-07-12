#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

int n, k, elem = -1, s, f, c;
long long int maxcost = -1, cur1, cur2;

struct vertex {
	int a, fp, sp1, sp2, num, visited, un;
	vector<pair<int, int>> friends;
	long long int fcost, scost;
};

vector<vertex> g;

int main()
{
	scanf_s("%d%d", &n, &k);
	g.resize(n);

	for (int i = 0; i < n; i++) {
		scanf_s("%d", &c);
		g[i].num = 1;
		g[i].a = c;
		g[i].visited = 0;
		g[i].fcost = 0; g[i].scost = -1;
		g[i].sp1 = g[i].sp2 = g[i].fp = -1;
	}

	for (int i = 0; i < k; i++) {
		scanf_s("%d%d%d", &s, &f, &c);
		s--; f--;
		g[s].friends.push_back({ f, c });
		g[f].friends.push_back({ s, c });
	}

	queue<int> fire;

	for (int i = 0; i < n; i++) {
		if (g[i].friends.size() < 2) fire.push(i);
		g[i].un = g[i].friends.size();
	}

	while (!fire.empty()) {
		int v = fire.front(), par = -1, to;
		cur1 = cur2 = -1;
		fire.pop();

		if (g[v].un > 1 && !g[v].visited) fire.push(v);

		if (g[v].un < 2 && !g[v].visited) {
			g[v].visited = true;
			for (int i = 0; i < g[v].friends.size(); i++) {
				to = g[v].friends[i].first;
				if (g[to].visited) {
					if (g[to].fcost + g[v].friends[i].second > g[v].fcost) {
						g[v].fcost = g[to].fcost + g[v].friends[i].second;
						g[v].fp = to;
						g[v].num = g[to].num + 1;
					}
					if (g[to].fcost + g[v].friends[i].second > cur2) {
						cur2 = g[to].fcost + g[v].friends[i].second;
						g[v].sp2 = to;
					}
					if (cur2 > cur1) {
						swap(cur2, cur1);
						swap(g[v].sp1, g[v].sp2);
					}
				}
				else par = g[v].friends[i].first;
			}
			g[v].fcost += g[v].a;

			if (g[v].sp2 != -1) {
				g[v].scost = cur1 + cur2 + g[v].a;
			}

			if (par != -1) {
				g[par].un--;
				fire.push(par);
			}

			if (g[v].fcost > maxcost || g[v].scost > maxcost) {
				maxcost = max(g[v].fcost, g[v].scost);
				elem = v;
			}
		}
	}

	printf("%lld\n", maxcost);

	vector<int> answ;

	if (g[elem].fcost >= g[elem].scost) {
		printf("%d\n", g[elem].num);
		while (elem != -1) {
			printf("%d ", elem + 1);
			elem = g[elem].fp;
		}
	}
	else {
		printf("%d\n", g[g[elem].sp1].num + g[g[elem].sp2].num + 1);

		int k = g[elem].sp1;
		while (k != -1) {
			answ.push_back(k);
			k = g[k].fp;
		}
		for (int i = answ.size() - 1; i >= 0; i--) printf("%d ", answ[i] + 1);

		printf("%d ", elem + 1);

		k = g[elem].sp2;
		while (k != -1) {
			printf("%d ", k + 1);
			k = g[k].fp;
		}
	}
}