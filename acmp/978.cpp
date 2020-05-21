#include <cmath>
#include <map>
#include <iostream>
#include <algorithm>
using namespace std;
  
int main()
{
    long long int n,c,i,p;
    int r = 1e9;
    cin >> n;
    map<long long int, int> k, f;
    c= n;
    for (i = 2; i <= sqrt((double)c); i++) {
        while (c%i == 0) {
            k[i]++;
            c = c / i;
        }
    }
    if (c > 1) k[c]++;
  
    for (auto it = k.begin(); it != k.end(); it++) {
        p = it->first;
        while (p <= n) {
            f[it->first] += n / p;
            p = p*(it->first);
        }
        r = min(r, f[it->first] / (it->second));
    }
    cout << r;
}

