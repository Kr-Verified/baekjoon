#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

int order = 0, scc_count = 0;
stack<int> _stack;

int get_idx(int n) {
    if (n > 0) return (n-1)*2;
    return (-n-1)*2+1;
}

void dfs(int u, vector<vector<int>>& g, vector<int>& scc_id, vector<bool>& on_stack, vector<int>& dfn, vector<int>& low) {
    dfn[u] = low[u] = ++order;
    on_stack[u] = true;
    _stack.push(u);

    for (const auto& v : g[u]) {
        if (dfn[v] == 0) {
            dfs(v, g, scc_id, on_stack, dfn, low);
            low[u] = min(low[u], low[v]);
        }else if (on_stack[v]) low[u] = min(low[u], dfn[v]);
    }

    if (dfn[u] == low[u]) {
        while (true) {
            const int v = _stack.top();
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
        int n, m;
        cin >> n >> m;
        if (n == 0 && m == 0) return 0;

        vector<vector<int>> g(2*m, vector<int>());
        vector<int> dfn(2*m, 0), low(2*m, 0), scc_id(2*m, -1);
        vector<bool> on_stack(2*m, false);

        for (int i = 0; i < n; i++) {
            int u, v;
            cin >> u >> v;
            u = get_idx(u);
            v = get_idx(v);
            g[u].push_back(v^1);
            g[v].push_back(u^1);
        }

        for (int i = 0; i < 2*m; i++) if (dfn[i] == 0) dfs(i, g, scc_id, on_stack, dfn, low);

        bool possible = true;
        for (int i = 1; i <= m; i++) {
            if (scc_id[(i-1)*2] == scc_id[(i-1)*2+1]) {
                possible = false;
                break;
            }
        }

        cout << (possible?1:0) << endl;
    }
}