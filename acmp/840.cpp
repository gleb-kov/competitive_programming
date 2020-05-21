#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <iomanip>
#include <cmath>
#include <tuple>
#include <algorithm>
using namespace std;
 
struct p {
    double x, y, z, r;
    bool per = false;
};
 
int main()
{
    double x, y, z, r, po;
    int n;
    cin >> x >> y >> z >> r;
    cin >> n;
    vector<p> sphere(n+1);
    sphere[0] = { x,y,z,r };
    for (int i = 1; i <= n; i++) {
        cin >> sphere[i].x >> sphere[i].y >> sphere[i].z >> sphere[i].r;
        for (int j = 0; j < i; j++) {
            po = (sphere[j].x - sphere[i].x)*(sphere[j].x - sphere[i].x) + (sphere[j].y - sphere[i].y)*(sphere[j].y - sphere[i].y) + (sphere[j].z - sphere[i].z)*(sphere[j].z - sphere[i].z);
            if (po < (sphere[j].r + sphere[i].r)*(sphere[j].r + sphere[i].r)) {
                sphere[i].per = true;
                sphere[j].per = true;
            }
        }
        bool g = true;
        for (int j = 0; j <= i; j++) {
            if (!sphere[j].per) g = false;
        }
        if (g) {
            cout << i;
            return 0;
        }
    }
    cout << 0;
    return 0;
}

