#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <iomanip>

using namespace std;
typedef long long int ll;
typedef long double ld;

const ld pi = acos(-1.00);
#define Epsilon 1E-10
struct info {
    ld x, y, z;
};

double arccos(double X) {
    if (abs(X) < Epsilon) return pi / 2;
    if (X <= -1) return pi;
    if (X >= 1) return 0;
    if (X > 0) return atan(sqrt(1 - X * X) / X);
    return pi + atan(sqrt(1 - X * X) / X);
}

int main() {
    int n, m;
    ld r, w, l, x, y, z, minpo, curpo, curcos;
    cin >> n >> m >> r;
    vector<info> places(m);
    for (int i = 0; i < m; i++) {
        cin >> w >> l;
        places[i].z = sin(pi * w / 180.0);
        places[i].x = cos(pi * l / 180.0) * cos(pi * w / 180.0);
        places[i].y = sin(pi * l / 180.0) * cos(pi * w / 180.0);
    }

    for (int i = 0; i < n; i++) {
        cin >> w >> l;
        x = cos(pi * l / 180.0) * cos(pi * w / 180.0);
        z = sin(pi * w / 180.0);
        y = sin(pi * l / 180.0) * cos(pi * w / 180.0);

        minpo = 1e10;
        for (int j = 0; j < m; j++) {
            curpo = (x - places[j].x) * (x - places[j].x) + (y - places[j].y) * (y - places[j].y) +
                    (z - places[j].z) * (z - places[j].z);
            minpo = min(minpo, curpo);
        }
        curcos = 1 - minpo / 2;
        cout << fixed << setprecision(2) << arccos(curcos) * r << endl;
    }
}
