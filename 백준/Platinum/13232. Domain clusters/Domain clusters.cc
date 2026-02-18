#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>

using namespace std;

int order, scc_count;
stack<int> _stack;

void dfs(const int u, vector<vector<int>>& g, vector<int>& dfn, vector<int>& low, vector<int>& scc_id, vector<bool>& on_stack) {
    dfn[u] = low[u] = ++order;
    on_stack[u] = true;
    _stack.push(u);

    for (const auto& v: g[u]) {
        if (dfn[v] == 0) {
            dfs(v, g, dfn, low, scc_id, on_stack);
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
    cin >> n >> m;

    vector<vector<int>> g(n);
    vector<int> dfn(n, 0), low(n, 0), scc_id(n, -1);
    vector<bool> on_stack(n, false);

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--;v--;
        g[u].push_back(v);
    }

    for (int u = 0; u < n; u++) if (dfn[u] == 0) dfs(u, g, dfn, low, scc_id, on_stack);

    vector<int> scc_size(scc_count);

    for (int i = 0; i < n; i++) scc_size[scc_id[i]]++;

    int max_v = 0;
    for (int i = 0; i < scc_count; i++) max_v = max(max_v, scc_size[i]);

    cout << max_v << endl;

    return 0;
}