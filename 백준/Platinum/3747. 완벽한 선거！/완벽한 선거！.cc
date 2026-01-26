#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>

using namespace std;

int order = 0, scc_count = 0;

int get_idx(int u) {
    if (u > 0) return (u-1)*2;
    return (-u-1)*2+1;
}

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
    while (cin >> n >> m) {
        vector<vector<int>> g(2*n);
        order = scc_count = 0;
        stack<int> _stack;
        vector<int> dfn(2*n, 0), low(2*n, 0), scc_id(2*n, -1);
        vector<bool> on_stack(2*n, false);
        for (int i = 0; i < m; i++) {
            int u, v;
            cin >> u >> v;
            u = get_idx(u);
            v = get_idx(v);
            g[u^1].push_back(v);
            g[v^1].push_back(u);
        }

        for (int i = 0; i < 2*n; i++) if (dfn[i] == 0) dfs(i, g, dfn, low, scc_id, on_stack, _stack);

        bool possible = true;
        for (int i = 1; i <= n; i++) {
            if (scc_id[(i-1)*2] == scc_id[(i-1)*2+1]) {
                possible = false;
                break;
            }
        }

        cout << (possible?1:0) << '\n';
    }

    return 0;
}