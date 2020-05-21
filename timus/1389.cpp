#include <algorithm>
#include <queue>
#include <vector>
#include <cmath>
#include <stack>

#pragma comment(linker, "/STACK:16777216")
using namespace std;

int n, k, elem = -1, s, f, c;
int maxres = -1, cur;

struct vertex {
    int num, visited, un;
    vector<int> friends;
    int fcost, scost;
    int fp;
};

vector<vertex> g;
vector<bool> visi;
vector<pair<int, int>> answ;

void dfs(int v, int type) {
    visi[v] = true;
    if (g[v].fp != -1) {
        if (type == 1) {
            printf("%d %d\n", v + 1, g[v].fp + 1);
            dfs(g[v].fp, 2);
        }

        for (int i = 0; i < g[v].friends.size(); i++) {
            if (!visi[g[v].friends[i]]) {
                if (g[g[v].friends[i]].fcost <= g[g[v].friends[i]].scost) dfs(g[v].friends[i], 2);
                else dfs(g[v].friends[i], 1);
            }
        }
    }
}

int main() {
    scanf_s("%d%d", &n, &k);
    g.resize(n);
    visi.resize(n, false);
    for (int i = 0; i < n; i++) {
        g[i].num = 1;
        g[i].visited = 0;
        g[i].fcost = 0;
        g[i].scost = 0;
        g[i].fp = -1;
    }

    for (int i = 0; i < k; i++) {
        scanf_s("%d%d", &s, &f);
        s--;
        f--;
        g[s].friends.push_back(f);
        g[f].friends.push_back(s);
    }

    queue<int> fire;

    for (int i = 0; i < n; i++) {
        if (g[i].friends.size() < 2) {
            fire.push(i);
        }
        g[i].un = g[i].friends.size();
    }

    while (!fire.empty()) {
        int v = fire.front(), par = -1, to;
        cur = 0 - n;
        fire.pop();

        if (g[v].un > 1 && !g[v].visited) fire.push(v);

        if (g[v].un < 2 && !g[v].visited) {
            g[v].visited = true;

            for (int i = 0; i < g[v].friends.size(); i++) {
                to = g[v].friends[i];
                if (g[to].visited) {
                    int te = g[to].scost - max(g[to].fcost, g[to].scost);
                    if (te > cur || g[v].fp == -1) {
                        cur = te;
                        g[v].fp = to;
                    }
                    g[v].scost += max(g[to].fcost, g[to].scost);
                } else par = g[v].friends[i];
            }

            if (g[v].fp != -1) g[v].fcost = g[v].scost + cur + 1;

            if (par != -1) {
                g[par].un--;
                fire.push(par);
            }

            if (g[v].fcost > maxres || g[v].scost > maxres) {
                maxres = max(g[v].fcost, g[v].scost);
                elem = v;
            }
        }
    }

    printf("%d\n", maxres);
    if (g[elem].fcost >= g[elem].scost) dfs(elem, 1);
    else dfs(elem, 2);
}