#include <iostream>
#include <vector>
#include <stack>
#include <queue>
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

    int n, m, s, t;
    cin >> n >> m >> s >> t;

    vector<vector<int>> g(n);
    vector<int> dfn(n, 0), low(n, 0), scc_id(n, -1);
    vector<bool> on_stack(n, false);
    stack<int> _stack;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        g[u].push_back(v);
    }

    for (int u = 0; u < n; u++) if (dfn[u] == 0) dfs(u, g, dfn, low, scc_id, on_stack, _stack);
    vector<vector<int>> dag_g(scc_count);
    vector<int> scc_size(scc_count, 0);
    vector<int> indeg(scc_count, 0);
    for (int u = 0; u < n; u++) {
        scc_size[scc_id[u]]++;
        for (const auto &v : g[u]) if (scc_id[u] != scc_id[v]) dag_g[scc_id[u]].push_back(scc_id[v]);
    }

    for (int i = 0; i < scc_count; i++) {
        sort(dag_g[i].begin(), dag_g[i].end());
        dag_g[i].erase(unique(dag_g[i].begin(), dag_g[i].end()), dag_g[i].end());
        for (const auto &v : dag_g[i]) indeg[v]++;
    }

    queue<int> q;
    vector<int> seq;
    for (int i = 0; i < scc_count; i++) if (indeg[i] == 0) q.push(i);

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        seq.push_back(u);
        for (const auto &v : dag_g[u]) if (--indeg[v] == 0) q.push(v);
    }

    vector<int> dp(scc_count, 0);
    dp[scc_id[s-1]] = scc_size[scc_id[s-1]];
    for (const auto &u : seq) {
        if (dp[u] == 0) continue;
        for (const auto &v : dag_g[u]) {
            dp[v] = max(dp[v], dp[u]+scc_size[v]);
        }
    }

    cout << dp[scc_id[t-1]] << '\n';

    return 0;
}