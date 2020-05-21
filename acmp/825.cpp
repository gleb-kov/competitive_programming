#include <iostream>
#include <cmath>
 
long long k, n, t;
 
int main() {
    std::cin >> n;
    while (n--) {
        std::cin >> k;
        t = (k + sqrtl(5 * k* k)) / 2;
        std::cout << t << " " << t+k << "\n";
    }
}

