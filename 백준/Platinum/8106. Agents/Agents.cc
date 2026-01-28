#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

int order, scc_count;
stack<int> _stack;

void dfs(int u, vector<vector<int>>& g, vector<int>& scc_id, vector<int>& dfn, vector<bool>& on_stack, vector<int>& low) {
    dfn[u] = low[u] = ++order;
    on_stack[u] = true;
    _stack.push(u);

    for (const auto& v : g[u]) {
        if (dfn[v] == 0) {
            dfs(v, g, scc_id, dfn, on_stack, low);
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

    int n;
    cin >> n;
    vector<vector<int>> g(n+1);
    vector<int> dfn(n+1, 0), low(n+1, 0), scc_id(n+1, -1);
    vector<bool> on_stack(n+1, false);

    int bribery_n;
    cin >> bribery_n;
    vector<pair<int, int>> briberies(bribery_n);
    for (int i = 0; i < bribery_n; i++) cin >> briberies[i].first >> briberies[i].second;

    int m;
    cin >> m;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
    }

    for (int u = 1; u <= n; u++) if (dfn[u] == 0) dfs(u, g, scc_id, dfn, on_stack, low);

    vector<vector<int>> dag_graph(scc_count);
    vector<int> indegs(scc_count, 0);
    for (int u = 1; u <= n; u++) {
        for (const auto& v : g[u]) {
            if (scc_id[u] != scc_id[v]) dag_graph[scc_id[u]].push_back(scc_id[v]);
        }
    }
    for (int i = 0; i < scc_count; i++) {
        sort(dag_graph[i].begin(), dag_graph[i].end());
        dag_graph[i].erase(unique(dag_graph[i].begin(), dag_graph[i].end()), dag_graph[i].end());
        for (const auto& v : dag_graph[i]) indegs[v]++;
    }

    vector<bool> zero_dag(scc_count, false);
    for (int i = 0; i < scc_count; i++) if (indegs[i] == 0) zero_dag[i] = true;

    int result = 0;
    int min_number = 10000;
    for (int i = 0; i < scc_count; i++) {
        if (zero_dag[i]) {
            int min_price = 100000;
            for (const auto& bribery : briberies) {
                if (scc_id[bribery.first] == i) {
                    min_price = min(min_price, bribery.second);
                    zero_dag[i] = false;
                }
            }
            if (min_price != 100000) result += min_price;
            else {
                for (int agnet = 1; agnet <= n; agnet++) {
                    if (scc_id[agnet] == i) {
                        min_number = min(min_number, agnet);
                        break;
                    }
                }
            }
        }
    }

    bool is_possible = true;
    for (int i = 0; i < scc_count; i++) if (zero_dag[i]) is_possible = false;
    if (is_possible) {
        cout << "TAK\n" << result << '\n';
    }else {
        cout << "NIE\n" << min_number << '\n';
    }
    return 0;
}