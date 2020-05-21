#include <iostream>
#include <map>
#include <cmath>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;
typedef long long int ll;
 
ll delta(char a, char b) {
    int e = abs(b - a);
    return min(26 - e, e);
}
 
int main()
{
    ll res = 0;
    map<char, ll> col, col2;
    string a, b;
    getline(cin, a);
    getline(cin, b);
    for (int i = 0; i < a.size(); i++) col[a[i]]++;
    for (int i = 0; i < b.size(); i++) col2[b[i]]++;
    for (auto it = col.begin(); it != col.end(); it++) {
        for (auto ir = col2.begin(); ir != col2.end(); ir++) {
            res += delta(ir->first, it->first)*it->second*ir->second;
        }
    }
    res = res*a.size();
    cout << res;
}

