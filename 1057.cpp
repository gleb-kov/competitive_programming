#include <iostream>
#include <array>
#include <vector>
#include <cmath>

std::array<std::array<int64_t, 32>, 32> c_table;

int64_t solve_prefix(int32_t n, size_t k, int64_t b) {
    std::vector<int64_t> digit;
    size_t nonzero = 0;
    while (n) {
        digit.push_back(n % b);
        if (n % b != 0) nonzero++;
        n /= b;
    }
    int64_t res = (nonzero == k);
    if (k > digit.size()) return 0;

    for (size_t i = k; i < digit.size(); i++) res += c_table[i - 1][k - 1];
    digit.pop_back();

    size_t cnt = digit.size(), cur = 1;
    for (size_t i = cnt; i > 0 && cur <= k; i--) {
        if (digit[i - 1] == 0) continue;
        res += c_table[i - 1][k - cur];
        cur++;
    }
    return res;
}

int64_t solve_prefix10(int64_t n, size_t k, int64_t cur = 0, size_t step = 0, size_t filled = 0) {
    return (step == 10 || filled >= k || cur > n ?
            (int64_t)(cur <= n && filled == k) :
            solve_prefix10(n, k, cur, step + 1, filled) +
            solve_prefix10(n, k, cur + pow(10, step), step + 1, filled + 1));
}

int main() {
    c_table[0].fill(0);
    c_table[0][0] = 1;
    for (size_t i = 1; i < 32; i++) {
        c_table[i][0] = 1;
        for (size_t j = 1; j < 32; j++)
            c_table[i][j] = c_table[i - 1][j] + c_table[i - 1][j - 1];
    }
    size_t k;
    int64_t x, y, b, result = 0;
    std::cin >> x >> y >> k >> b;
    result = (b == 10 ?
              solve_prefix10(y, k) - solve_prefix10(x - 1, k) :
              solve_prefix(y, k, b) - solve_prefix(x - 1, k, b));
    std::cout << result;
}

