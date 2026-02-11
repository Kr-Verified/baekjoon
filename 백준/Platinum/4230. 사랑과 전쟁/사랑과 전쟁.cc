#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <cctype>

using namespace std;

int order, scc_count;

int get(string s) {
    string number;
    char gen = '\0';
    for (const auto& c : s) {
        if (isdigit(c)) number += c;
        else if (isalpha(c)) gen = c;
    }

    if (gen == 'h') return stoi(number) * 2;
    if (gen == 'w') return stoi(number) * 2 + 1;
    return -1;
}

void dfs(const int u, vector<vector<int>>& g, vector<int>& dfn, vector<int>& low, vector<int>& scc_id, vector<bool>& on_stack, stack<int>& _stack) {
    dfn[u] = low[u] = ++order;
    on_stack[u] = true;
    _stack.push(u);

    for (const auto& v : g[u]) {
        if (dfn[v] == 0) {
            dfs(v, g, dfn, low, scc_id, on_stack, _stack);
            low[u] = min(low[u], low[v]);
        }else if (on_stack[v]) low[u] = min(low[u], dfn[v]);
    }

    if (dfn[u] == low[u]) {
        while (true) {
            int v = _stack.top();
            _stack.pop();
            on_stack[v] = false;

            scc_id[v] = scc_count;
            if (u == v) break;
        }
        scc_count++;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, m;
    while (true) {
        order = scc_count = 0;
        cin >> n >> m;
        if (n == 0 && m == 0) break;

        vector<vector<int>> g(2*n);
        vector<int> dfn(2*n, 0), low(2*n, 0), scc_id(2*n, -1);
        vector<bool> on_stack(2*n, 0);
        stack<int> _stack;

        g[0].push_back(1);
        for (int i = 0; i < m; i++) {
            string a, b;
            cin >> a >> b;

            int u = get(a), v = get(b);
            g[u^1].push_back(v);
            g[v^1].push_back(u);
        }

        for (int u = 0; u < 2*n; u++) if (dfn[u] == 0) dfs(u, g, dfn, low, scc_id, on_stack, _stack);

        bool is_possible = true;
        for (int u = 0; u < n; u++) {
            if (scc_id[2*u] == scc_id[2*u+1]) {
                is_possible = false;
                break;
            }
        }

        if (!is_possible) cout << "bad luck\n";
        else {
            for (int i = 1; i < n; i++) {
                if (scc_id[2*i] < scc_id[2*i+1]) cout << i << "h ";
                else cout << i << "w ";
            }
            cout << '\n';
        }
    }

    return 0;
}