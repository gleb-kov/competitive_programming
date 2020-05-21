#include <iostream>
#include <string>
#include <vector>
#include <set>
 
using namespace std;
 
bool win = false;
 
void check_win(vector<int> &v) {
    for (int t : v) win |= (t == 24);
}
 
vector<int> game(vector<int> const &lhs, vector<int> const &rhs) {
    set<int> dif;
    for (int l : lhs){
        for (int r : rhs) {
            dif.insert(l + r);
            dif.insert(l * r);
            dif.insert(l - r);
            dif.insert(- l + r);
            dif.insert(- l - r);
            dif.insert(- l * r);
        }
    }
    vector<int> res;
    for(int t : dif) res.push_back(t);
    return res;
}
 
vector<int> game(int l, int r) {
    return game(vector<int>{l}, vector<int>{r});
}
 
vector<int> game(vector<int> const &lhs, int r) {
    return game(lhs, vector<int>{r});
}
 
vector<int> game(int l, vector<int> const &rhs) {
    return game(vector<int>{l}, rhs);
}
 
int main() {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    auto a1 = game(game(game(a, b), c), d);
    auto a2 = game(game(a, b), game(c, d));
    auto a3 = game(game(a, game(b, c)), d);
    auto a4 = game(a, game(game(b, c), d));
    auto a5 = game(a, game(b, game(c, d)));
    check_win(a1);
    check_win(a2);
    check_win(a3);
    check_win(a4);
    check_win(a5);
    cout << (win ? "YES" : "NO");
    return 0;
}

