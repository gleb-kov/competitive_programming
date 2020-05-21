#include <iostream>
#include <vector>
using namespace std;
  
int n, m,a,b,w = 0,u=0;
vector<vector<int>> g;
vector<int> s,d;
  
void f(int v) {
    d[v] = true;
    if (s[v] % 2) u++;
    for (int i = 0; i < g[v].size(); i++) if (!d[g[v][i]]) f(g[v][i]);
}
  
int main()
{
    cin >> n >> m;
    g.resize(n);
    d.resize(n, 0);
    s.resize(n, 0);
  
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        s[--a]++; s[--b]++;
        g[a].push_back(b);
        g[b].push_back(a);
    }
  
    for (int i = 0; i < n; i++) {
        if (!d[i]) {
            u = 0;
            f(i);
            w += u / 2;
            if (!u && s[i]) w++;
        }
    }
    cout << w;
}

