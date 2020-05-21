#include <iostream>
#include <cmath>
#include <algorithm>
#include <iomanip>
#include <vector>
#include <string>
using namespace std;
typedef long long int ll;
 
ll a, b, c, d;
 
char is_prime(ll n) {
    for (ll i = 2; i <= sqrtl((double)n); i++) {
        if (n%i == 0) return false;
    }
    return true;
}
 
char check(ll n) {
    for (ll s = a; s <= b; s++) {
        if (n%s == 0 && n / s >= c && n / s <= d) return false;
    }
    return true;
}
 
int main()
{
    cin >> a >> b >> c >> d;
    if (b - a > d - c) {
        swap(b, d);
        swap(a, c);
    }
    for (ll i = a*c + 1;i<=b*d+1; i++) {
        if (check(i)) {
            cout << i;
            return 0;
        }
    }
}

