#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>
#include <algorithm>
using namespace std;
typedef long double ld;
 
struct color {
    double x1, x2, y1, y2;
    double a, b, c;
};
 
int main() {
    double r, x,y; int k;
    cin >> r >> k;
    vector<int> dp(k + 1, 1);
    vector<color> lines(k);
    for (int i = 0; i < k; i++) {
        cin >> lines[i].x1 >> lines[i].y1 >> lines[i].x2 >> lines[i].y2;
        lines[i].a = lines[i].y1 - lines[i].y2;
        lines[i].b = lines[i].x2 - lines[i].x1;
        lines[i].c = 0 - (lines[i].a * lines[i].x1 + lines[i].b * lines[i].y1);
    }
    for (int i = 0; i < k; i++) {
        int col = 0;
        for (int j = 0; j < i; j++) {
            y = (lines[i].a*lines[j].c - lines[i].c*lines[j].a) / (lines[j].a*lines[i].b - lines[i].a*lines[j].b);
            x = (lines[i].c*lines[j].b - lines[i].b*lines[j].c) / (lines[j].a*lines[i].b - lines[i].a*lines[j].b);
            if ((x*x + y*y) < r*r) col++;
        }
        dp[i + 1] = dp[i] + col + 1;
    }
    cout << dp[k];
}

