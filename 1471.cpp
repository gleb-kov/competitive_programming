#include <map>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>
#include <cmath>
#include <stack>
#include <iomanip>

#pragma comment(linker, "/STACK:16777216")
using namespace std;

int n, pos = 0;
vector<vector<pair<int, int>>> g;
vector<bool> visited;
vector<int> weight, depth, last;
vector<pair<int, int>> d, t;

void dfs(int v) {
    visited[v] = true;
    last[v] = pos;
    d[pos] = {depth[v], v};
    pos++;
    for (int i = 0; i < g[v].size(); i++) {
        if (!visited[g[v][i].first]) {
            depth[g[v][i].first] = depth[v] + 1;
            weight[g[v][i].first] = weight[v] + g[v][i].second;
            dfs(g[v][i].first);
            d[pos] = {depth[v], v};
            pos++;
        }
    }
}

void build(int i, int li, int ri) {
    if (li + 1 == ri) {
        t[i] = {d[li].first, d[li].second};
    } else {
        int c = (li + ri) / 2;
        build(2 * i + 1, li, c);
        build(2 * i + 2, c, ri);
        t[i] = t[2 * i + 1];
        if (t[2 * i + 2].first < t[i].first) t[i] = t[2 * i + 2];
    }
}

int lca(int i, int li, int ri, int l, int r) {
    if (li == l && r == ri) {
        return t[i].second;
    } else {
        int c = (li + ri) / 2;
        if (r <= c) return lca(2 * i + 1, li, c, l, r);
        if (l >= c) return lca(2 * i + 2, c, ri, l, r);
        int w = lca(2 * i + 1, li, c, l, c);
        int e = lca(2 * i + 2, c, ri, c, r);
        if (depth[w] < depth[e]) return w;
        return e;
    }
}

int main() {
    int a, b, w, m;
    scanf("%d", &n);
    g.resize(n);
    visited.resize(n, false);
    weight.resize(n, 0);
    last.resize(n);
    d.resize(2 * n - 1);
    t.resize(8 * n - 4);
    depth.resize(n, 0);

    for (int i = 0; i < n - 1; i++) {
        scanf("%d%d%d", &a, &b, &w);
        g[a].push_back({b, w});
        g[b].push_back({a, w});
    }
    dfs(0);

    build(0, 0, 2 * n - 1);
    scanf("%d", &m);

    for (int i = 0; i < m; i++) {
        scanf("%d%d", &a, &b);
        int res = lca(0, 0, 2 * n - 1, min(last[a], last[b]), max(last[a], last[b]) + 1);
        printf("%d\n", weight[a] + weight[b] - 2 * weight[res]);
    }
}