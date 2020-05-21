#include <iostream>
#include <vector>
using namespace std;
 
int main()
{
    int n,i, j,mod,t = 2501;
    cin>>n>>mod;
    vector<vector<int>>c(t);
    vector<int>d(n+1,0);
    d[1] = 1;
    for (i=0;i<t;i++) {
        c[i].resize(i+1,1);
        for (j=1;j<i;j++) c[i][j]=(c[i-1][j-1]+c[i-1][j])%mod;
    }
    for (i=2;i<=n;i++)
        for (j = (i/3) + (i%3 != 0); j <= i/2; j++) d[i]=(d[i]+d[j]*1ll*c[j][3*j-i])%mod;
    cout<<d[n];
}

