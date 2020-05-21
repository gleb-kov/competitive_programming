#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <stack>
 
using namespace std;
 
unordered_map<string, bool> values;
 
struct node {
    virtual bool eval() = 0;
};
 
struct bin_node : node {
    vector<node *> hs;
    char op;
 
    explicit bin_node(char sign) : op(sign) {};
 
    void add(node *v) {
        hs.push_back(v);
    }
 
    bool eval() override {
        bool fold = op == '&';
        for (node * t : hs) {
            bool c = t->eval();
            if (op == '&') fold &= c;
            else fold |= c;
        }
        return fold;
    }
};
 
struct not_node : node {
    node * operand;
 
    not_node(node * tmp) : operand(tmp) {};
 
    bool eval() override {
        return !operand->eval();
    }
};
 
struct var_node : node {
    string name;
 
    explicit var_node(string const &n) : name(n) {};
 
    bool eval() override {
        return values[name];
    }
};
 
size_t l = 0;
int token = 0;
void next_token(string const &s) {
    while (l < s.size() && s[l] == ' ') l++;
    if (l >= s.size()) {
        token = 0;
        return;
    }
    static const vector<pair<string, int>> tokens = {
            {"(", 1},
            {")", 2},
            {",", 3},
            {"AND", 4},
            {"OR", 5},
            {"NOT", 6}
    };
    for (auto t : tokens) {
        size_t i = 0;
        for (; i < t.first.size(); i++) {
            if (l + i == s.size()) break;
            if (t.first[i] != s[l + i]) break;
        }
        if (i == t.first.size()) {
            token = t.second;
            l += t.first.size();
            return;
        }
    }
    token = 7;
}
 
node * parse(string const &s) {
    next_token(s);
    if (token == 0) return nullptr;
    if (token == 6) {
        l++;
        node *tmp = parse(s);
        l++;
        return new not_node(tmp);
    }
    if (token == 7) {
        string name;
        name += s[l];
        l++;
        return new var_node(name);
    }
    bin_node * res;
    if (token == 4) res = new bin_node('&');
    if (token == 5) res = new bin_node('|');
    next_token(s);
    while(token != 2) {
        res->add(parse(s));
        next_token(s);
        if (token == 3) continue;
    }
    return res;
}
 
int main() {
    string s;
    cin >> s;
    node * res = parse(s);
    int n, k;
    cin >> n >> k;
    for(int i = 0; i < n; i++) {
        for (int j = 0; j < k; j++) {
            cin >> s;
            string name;
            name += s[0];
            values[name] = s[2] == 'T';
        }
        cout << (res->eval() ? "TRUE" : "FALSE") << '\n';
    }
}

