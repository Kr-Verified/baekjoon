#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <algorithm>

using namespace std;

int order = 0, scc_count = 0;
stack<int> _stack;

void dfs(int u, vector<vector<int>>& graph, vector<int>& dfn, vector<int>& low, vector<int>& scc_id, vector<bool>& on_stack) {
    dfn[u] = low[u] = ++order;
    on_stack[u] = true;
    _stack.push(u);

    for (const auto v : graph[u]) {
        if (dfn[v] == 0) {
            dfs(v, graph, dfn, low, scc_id, on_stack);
            low[u] = min(low[u], low[v]);
        }else if (on_stack[v]) {
            low[u] = min(low[u], dfn[v]);
        }
    }

    if (low[u] == dfn[u]) {
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

    vector<int> city(n), dfn(n, 0), low(n, 0), scc_id(n, -1);
    vector<bool> on_stack(n, false);
    for (int i = 0; i < n; i++) cin >> city[i];

    vector<vector<int>> graph(n, vector<int>());
    for (int i = 0; i < n; i++) {
        string e;
        cin >> e;
        for (size_t k = 0; k < e.size(); k++) if (e[k] == '1') graph[i].push_back(k);
    }

    for (int u = 0; u < n; u++) if (dfn[u] == 0) dfs(u, graph, dfn, low, scc_id, on_stack);

    vector<int> scc_min(scc_count, 10000000);
    int result = 0;
    for (int i = 0; i < n; i++) if (scc_min[scc_id[i]] > city[i]) scc_min[scc_id[i]] = city[i];

    for (int i = 0; i < scc_count; i++) result += scc_min[i];

    cout << result << endl;
    return 0;
}