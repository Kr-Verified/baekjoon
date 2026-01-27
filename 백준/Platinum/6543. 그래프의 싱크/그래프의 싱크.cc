#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>

using namespace std;

int order, scc_count;

void dfs(int u, vector<vector<int>> &g, vector<int> &dfn, vector<int> &low, vector<int> &scc_id, vector<bool> &on_stack, stack<int> &_stack) {
    dfn[u] = low[u] = ++order;
    on_stack[u] = true;
    _stack.push(u);

    for (const auto &v : g[u]) {
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

    while (true) {
        order = 0, scc_count = 0;
        int n, m;
        if (!(cin >> n)) break;
        if (n == 0) break;
        cin >> m;

        vector<vector<int>> g(n);
        vector<int> dfn(n, 0), low(n, 0), scc_id(n, -1);
        vector<bool> on_stack(n, false);
        stack<int> _stack;
        for (int i = 0; i < m; i++) {
            int u, v;
            cin >> u >> v;
            u--; v--;
            g[u].push_back(v);
        }

        for (int u = 0; u < n; u++) if (dfn[u] == 0) dfs(u, g, dfn, low, scc_id, on_stack, _stack);

        vector<bool> is_bottom(scc_count, true);
        for (int u = 0; u < n; u++) {
            for (const auto &v : g[u]) if (scc_id[u] != scc_id[v]) {
                is_bottom[scc_id[u]] = false;
                break;
            }
        }

        for (int node = 0; node < n; node++) {
            if (is_bottom[scc_id[node]]) cout << node+1 << ' ';
        }
        cout << '\n';
    }

    return 0;
}