#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>

using namespace std;

int order, scc_count;
stack<int> _stack;

void dfs(const int u, vector<vector<int>>& g, vector<int>& dfn, vector<int>& low, vector<int>& scc_id, vector<bool>& on_stack) {
    dfn[u] = low[u] = ++order;
    _stack.push(u);
    on_stack[u] = true;

    for (const auto& v : g[u]) {
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
        int a, b;
        cin >> a >> b;
        a--; b--;
        g[a].push_back(b);
    }

    for (int u = 0; u < n; u++) if (dfn[u] == 0) dfs(u, g, dfn, low, scc_id, on_stack);

    vector<vector<int>> scc_g(scc_count);
    vector<int> scc_size(scc_count, 0);
    vector<int> indegs(scc_count, 0);
    for (int u = 0; u < n; u++) {
        scc_size[scc_id[u]]++;
        for (const int& v : g[u]) if (scc_id[u] != scc_id[v]) scc_g[scc_id[u]].push_back(scc_id[v]);
    }

    for (int u = 0; u < scc_count; u++) {
        sort(scc_g[u].begin(), scc_g[u].end());
        scc_g[u].erase(unique(scc_g[u].begin(), scc_g[u].end()), scc_g[u].end());
        for (const auto& v : scc_g[u]) indegs[v]++;
    }

    int zero_count = 0;
    int zero_id = 0;
    for (int i = 0; i < scc_count; i++) if (indegs[i] == 0) {
        zero_count++;
        zero_id = i;
    }

    if (zero_count != 1) cout << "0\n";
    else {
        cout << scc_size[zero_id] << '\n';
        for (int i = 0; i < n; i++) if (scc_id[i] == zero_id) cout << i+1 << " ";
        cout << '\n';
    }
    return 0;
}