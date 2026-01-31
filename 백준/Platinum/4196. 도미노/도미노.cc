#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>

using namespace std;

int order, scc_count;

void dfs(int u, vector<vector<int>>& g, vector<int>& scc_id, vector<int>& dfn, vector<int>& low, vector<bool>& on_stack, stack<int>& _stack) {
    dfn[u] = low[u] = ++order;
    on_stack[u] = true;
    _stack.push(u);

    for (const auto& v : g[u]) {
        if (dfn[v] == 0) {
            dfs(v, g, scc_id, dfn, low, on_stack, _stack);
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

    int t;
    cin >> t;
    while (t--) {
        order = 0, scc_count = 0;
        int n, m;
        cin >> n >> m;
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

        for (int u = 0; u < n; u++) if (dfn[u] == 0) dfs(u, g, scc_id, dfn, low, on_stack, _stack);

        vector<bool> zero_indegs(scc_count, true);
        for (int u = 0; u < n; u++) for (const auto& v : g[u]) if (scc_id[u] != scc_id[v]) zero_indegs[scc_id[v]] = false;

        int result = 0;
        for (int i = 0; i < scc_count; i++) if (zero_indegs[i]) result++;

        cout << result << '\n';
    }

    return 0;
}