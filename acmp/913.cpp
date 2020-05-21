#include <iostream>
#include <cmath>
#include <algorithm>
#include <iomanip>
#include <vector>
#include <string>
using namespace std;
 
struct road {
    double d, l, h;
};
 
int main()
{
    int n;
    double m, mintime=0,bestspeed,time;
    cin >> n >> m;
    vector<road> info(n);
    vector<double> tocheck;
    for (int i = 0; i < n; i++) {
        cin >> info[i].d >> info[i].l >> info[i].h;
        if(info[i].l < m) tocheck.push_back(info[i].l);
        mintime += info[i].d / m;
        if (m > info[i].l) mintime += info[i].h;
    }
    bestspeed = m;
    for (int i = 0; i < tocheck.size(); i++) {
        time = 0;
        for (int j = 0; j < n; j++) {
            time += info[j].d / tocheck[i];
            if (tocheck[i] > info[j].l) time += info[j].h;
        }
        if (time == mintime) bestspeed = max(bestspeed, tocheck[i]);
        if (time < mintime) {
            mintime = time;
            bestspeed = tocheck[i];
        }
    }
    cout << bestspeed;
}

