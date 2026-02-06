#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>

using namespace std;

int order, scc_count;
stack<int> _stack;

int get(int n) {
    if (n > 0) return (n-1)*2;
    return (-n-1)*2+1;
}

void dfs(int u, vector<vector<int>>& g, vector<int>& dfn, vector<int>& low, vector<int>& scc_id, vector<bool>& on_stack) {
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

    vector<vector<int>> g(2*n);
    vector<int> dfn(2*n, 0), low(2*n, 0), scc_id(2*n, 0);
    vector<bool> on_stack(2*n, false);

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        g[get(u)^1].push_back(get(v));
        g[get(v)^1].push_back(get(u));
    }

    for (int u = 0; u < 2*n; u++) if (dfn[u] == 0) dfs(u, g, dfn, low, scc_id, on_stack);

    bool is_possible = true;
    for (int i = 0; i < n; i++) {
        if (scc_id[i*2] == scc_id[i*2+1]) {
            is_possible = false;
            break;
        }
    }

    cout << (is_possible ? 1 : 0) << '\n';

    return 0;
}