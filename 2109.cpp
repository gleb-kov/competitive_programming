#include <vector>
#include <algorithm>
#include <cmath>
#include <iomanip>

#pragma comment(linker, "/STACK:16777216")
using namespace std;

int n;
vector<vector<int>> g, querys;
vector<int> dsu, asc, weight, answ, restree;
vector<bool> visited;

int dsu_get(int v) {
    if (v == dsu[v]) return v;
    return dsu[v] = dsu_get(dsu[v]);
}

void dsu_unite(int a, int b, int new_anc) {
    a = dsu_get(a);
    b = dsu_get(b);
    if (rand() & 1) swap(a, b);
    dsu[a] = b;
    asc[b] = new_anc;
}

void dfs(int v) {
    dsu[v] = v;
    asc[v] = v;
    visited[v] = true;
    for (int i = 0; i < g[v].size(); i++) {
        if (!visited[g[v][i]]) {
            weight[g[v][i]] = weight[v] + 1;
            dfs(g[v][i]);
            dsu_unite(v, g[v][i], v);
        }
    }
    for (int i = 0; i < querys[v].size(); i++) {
        if (visited[querys[v][i]]) {
            answ[min(v, querys[v][i])] = asc[dsu_get(querys[v][i])];
        }
    }
}

void buildrt(int i, int li, int ri) {
    if (li + 1 == ri) restree[i] = li;
    else {
        int c = (li + ri) / 2;
        buildrt(2 * i + 1, li, c);
        buildrt(2 * i + 2, c, ri);
        int cr = answ[c - 1];
        if (weight[restree[2 * i + 2]] < weight[cr]) cr = restree[2 * i + 2];
        if (weight[restree[2 * i + 1]] < weight[cr]) cr = restree[2 * i + 1];
        restree[i] = cr;
    }
}

int getansw(int i, int li, int ri, int l, int r) {
    if (li == l && r == ri) return restree[i];

    int c = (li + ri) / 2;
    if (r <= c) return getansw(2 * i + 1, li, c, l, r);
    if (l >= c) return getansw(2 * i + 2, c, ri, l, r);

    int an = answ[c - 1];
    int cur = getansw(2 * i + 1, li, c, l, c), cur2 = getansw(2 * i + 2, c, ri, c, r);

    if (weight[cur] < weight[an]) an = cur;
    if (weight[cur2] < weight[an]) an = cur2;
    return an;
}

int main() {
    int a, b, m;
    scanf_s("%d", &n);
    if (n > 1) {
        g.resize(n);
        querys.resize(n, vector<int>(2));
        restree.resize(4 * n);
        dsu.resize(n);
        asc.resize(n);
        visited.resize(n, false);
        weight.resize(n);
        weight[0] = 0;
        visited[0] = true;
        for (int i = 0; i < n - 1; i++) {
            scanf_s("%d%d", &a, &b);
            a--;
            b--;
            g[a].push_back(b);
            g[b].push_back(a);
        }

        answ.resize(n - 1);

        for (int i = 0; i < n - 1; i++) {
            querys[i].push_back(i + 1);
            querys[i + 1].push_back(i);
        }
        dfs(0);
        buildrt(0, 0, n);
        scanf_s("%d", &m);
        for (int i = 0; i < m; i++) {
            scanf_s("%d%d", &a, &b);
            a--;
            int res = getansw(0, 0, n, a, b);
            printf("%d\n", res + 1);
        }
    } else {
        scanf_s("%d", &m);
        for (int i = 0; i < m; i++) printf("1\n");
    }
}