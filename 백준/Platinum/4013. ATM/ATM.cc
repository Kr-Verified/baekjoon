#include <iostream>
#include <stack>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int order, scc_count;
stack<int> _stack;

void dfs(int u, vector<vector<int>>& g, vector<int>& scc_id, vector<int>& dfn, vector<int>& low, vector<bool>& on_stack) {
    dfn[u] = low[u] = ++order;
    on_stack[u] = true;
    _stack.push(u);

    for (const auto& v : g[u]) {
        if (dfn[v] == 0) {
            dfs(v, g, scc_id, dfn, low, on_stack);
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

int dfs_dp(int u, vector<int>& dp, vector<int>& scc_value, vector<vector<int>>& scc_graph, vector<bool>& can_go) {
    if (!can_go[u]) return 0;
    if (dp[u] != -1) return dp[u];

    int best = 0;
    for (const auto& scc : scc_graph[u]) {
        best = max(best, dfs_dp(scc, dp, scc_value, scc_graph, can_go));
    }

    return dp[u] = scc_value[u] + best;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> g(n);
    vector<int> dfn(n, 0), low(n, 0), scc_id(n, -1), value(n);
    vector<bool> on_stack(n, false);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        g[u].push_back(v);
    }
    for (int i = 0; i < n; i++) cin >> value[i];
    int s, p;
    cin >> s >> p;
    s--;
    vector<int> goal(p);
    for (int i = 0; i < p; i++) {
        cin >> goal[i];
        goal[i]--;
    }
    for (int u = 0; u < n; u++) if (dfn[u] == 0) dfs(u, g, scc_id, dfn, low, on_stack);

    vector<vector<int>> scc_graph(scc_count);
    vector<int> scc_value(scc_count, 0), dp(scc_count, -1);
    for (int u = 0; u < n; u++) {
        scc_value[scc_id[u]] += value[u];
        for (const auto& v : g[u]) {
            if (scc_id[u] != scc_id[v]) scc_graph[scc_id[u]].push_back(scc_id[v]);
        }
    }
    for (int i = 0; i < scc_count; i++) {
        sort(scc_graph[i].begin(), scc_graph[i].end());
        scc_graph[i].erase(unique(scc_graph[i].begin(), scc_graph[i].end()), scc_graph[i].end());
    }

    vector<vector<int>> rev_scc_graph(scc_count);
    for (int u = 0; u < scc_count; u++) for (const auto& v : scc_graph[u]) rev_scc_graph[v].push_back(u);

    vector<bool> can_go(scc_count, false);
    queue<int> q;

    for (const auto& g : goal) {
        can_go[scc_id[g]] = true;
        q.push(scc_id[g]);
    }

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (const auto v : rev_scc_graph[u]) {
            if (!can_go[v]) {
                can_go[v] = true;
                q.push(v);
            }
        }
    }

    dfs_dp(scc_id[s], dp, scc_value, scc_graph, can_go);
    
    cout << dp[scc_id[s]] << '\n';

    return 0;
}