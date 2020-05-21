#include <iostream>
 
int main(){
    long long n, m, a, i=2, t, lt, c;
    std::cin >> n >> m;
    a = (n / m) * m * (m - 1) / 2 + (n % m)*(1 + n % m)/2;
    if (n > m) {
        a += m * (n - m);
        n = m;
    }
     
    if (n*n < m){
        for(; i <=n; i++) a += m % i;
    } else { 
        t = m;
        lt = m;
        for (i = t / n; i*i <= n; i++){
            t = m / i;
            if (t > n) continue;
            if (lt > n) lt = n;
            c = (lt - t);
            a += c * (2 * (m % lt) + (c - 1) * (i - 1)) / 2;
            lt = t;
        }
        while (t) a += m % t--;
    }
    std::cout << a;
}

