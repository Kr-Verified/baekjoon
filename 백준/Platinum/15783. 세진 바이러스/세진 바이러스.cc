#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>

using namespace std;

stack<int> _stack;

int order, scc_count;

void dfs(const int u, vector<vector<int>>& g, vector<int>& dfn, vector<int>& low, vector<int>& scc_id, vector<bool>& on_stack) {
    dfn[u] = low[u] = ++order;
    _stack.push(u);
    on_stack[u] = true;

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
        g[u].push_back(v);
    }

    for (int i = 0; i < n; i++) if (dfn[i] == 0) dfs(i, g, dfn, low, scc_id, on_stack);

    vector<vector<int>> scc_g(scc_count);
    vector<int> indegs(scc_count, 0);
    for (int u = 0; u < n; u++) for (const auto& v: g[u]) if (scc_id[u] != scc_id[v]) scc_g[scc_id[u]].push_back(scc_id[v]);

    for (int u = 0; u < scc_count; u++) {
        sort(scc_g[u].begin(), scc_g[u].end());
        scc_g[u].erase(unique(scc_g[u].begin(), scc_g[u].end()),scc_g[u].end());
        for (const auto& v: scc_g[u]) indegs[v]++;
    }

    int result = 0;
    for (int i = 0; i < scc_count; i++) if (indegs[i] == 0) result++;

    cout << result << '\n';

    return 0;
}