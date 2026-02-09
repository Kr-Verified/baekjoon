#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>

using namespace std;

int order, scc_count;

void dfs(int u, vector<vector<int>>& g, vector<int>& dfn, vector<int>& low, vector<int>& scc_id, vector<bool>& on_stack, stack<int>& _stack) {
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

        vector<vector<int>> g(n);
        vector<int> dfn(n, 0), low(n, 0), scc_id(n, -1);
        vector<bool> on_stack(n, false);
        stack<int> _stack;

        for (int i = 0; i < m; i++) {
            int v, w, p;
            cin >> v >> w >> p;
            v--; w--;
            g[v].push_back(w);
            if (p == 2) g[w].push_back(v);
        }

        for (int u = 0; u < n; u++) if (dfn[u] == 0) dfs(u, g, dfn, low, scc_id, on_stack, _stack);

        cout << (scc_count == 1 ? 1 : 0) << '\n';
    }

    return 0;
}