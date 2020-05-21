#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <map>
using namespace std;
typedef long long int ll;
typedef long double ld;
 
int main() {
    ll answ = 0,a,b,c,z;
    int n;
    cin >> n;
    vector<pair<ll, ll>> points(n);
    vector<vector<char>> table(n, vector<char>(n, false));
     
    for (int i = 0; i < n; i++) {
        cin >> points[i].first >> points[i].second;
    }
    sort(points.begin(), points.end());
    for (int i = 0; i < n; i++) table[i][i] = true;
 
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
 
            if (table[i][j]) continue;
 
            a = points[i].second - points[j].second;
            b = points[j].first - points[i].first;
            c = 0 - (a*points[i].first + b*points[i].second);
 
            vector<int> online = { i };
            for (int k = 0; k < n; k++) {
                z = a*points[k].first + b*points[k].second + c;
                if (z == 0 && !table[i][k]) {
                    answ++;
                    online.push_back(k);
                }
            }
 
            for (int k = 0; k < online.size(); k++) {
                for (int e = 0; e < online.size(); e++) {
                    table[online[e]][online[k]] = true;
                    table[online[k]][online[e]] = true;
                }
            }
        }
    }
    cout << 2*answ;
}

