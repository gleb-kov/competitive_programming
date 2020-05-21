#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <iomanip>
#include <cmath>
#include <tuple>
#include <algorithm>
using namespace std;
 
int main()
{
    vector<vector<long long int>> par(2, vector<long long int>(6));
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 6; j++) cin >> par[i][j];
    }
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++) {
            if (par[i][j] > par[i][j+3]) swap(par[i][j], par[i][j+3]);
        }
    }
    int rx, lx, ry, ly, rz, lz;
    rx = min(par[0][3], par[1][3]);
    lx = max(par[0][0], par[1][0]);
 
    ry = min(par[0][4], par[1][4]);
    ly = max(par[0][1], par[1][1]);
 
    rz = min(par[0][5], par[1][5]);
    lz = max(par[0][2], par[1][2]);
 
    long long int v1,v2,v;
 
    if (rx <= lx || ry <= ly || rz <= lz) v=0;
    else {
        v = (rx - lx)*(ry - ly);
        v = v*(rz - lz);
    }
     
    v1 = (par[0][3] - par[0][0])*(par[0][4] - par[0][1]);
    v1 = v1*(par[0][5] - par[0][2]);
    v2 = (par[1][3] - par[1][0])*(par[1][4] - par[1][1]);
    v2 = v2*(par[1][5] - par[1][2]);
    cout << v1 + v2 - v;
    return 0;
}

