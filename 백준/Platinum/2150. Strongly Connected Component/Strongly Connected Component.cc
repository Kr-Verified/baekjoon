#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

int scc_count = 0, order = 0;
stack<int> _stack;

void dfs(int u, vector<vector<int>>& graph, vector<bool>& on_stack, vector<int>& scc_id, vector<int>& dfn, vector<int>& low) {
    dfn[u] = low[u] = ++order;
    on_stack[u] = true;
    _stack.push(u);

    for (const int &v : graph[u]) {
        if (dfn[v] == 0) {
            dfs(v, graph, on_stack, scc_id, dfn, low);
            low[u] = min(low[u], low[v]);
        }else if (on_stack[v]) low[u] = min(low[u], dfn[v]);
    }

    if (dfn[u] == low[u]) {
        while (true) {
            int v = _stack.top();
            _stack.pop();
            on_stack[v] = false;
            scc_id[v] = scc_count;
            if (v == u) break;
        }
        scc_count++;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int v, e;
    cin >> v >> e;

    vector<int> dfn(v+1, 0), low(v+1, 0), scc_id(v+1, -1);
    vector<vector<int>> graph(v+1, vector<int>());
    vector<bool> on_stack(v+1, false);

    for (int i = 0; i < e; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
    }

    for (int u = 1; u <= v; u++) if (dfn[u] == 0) dfs(u, graph, on_stack, scc_id, dfn, low);

    vector<vector<int>> scc_list(scc_count, vector<int>());
    for (int i = 0; i < scc_count; i++) {
        for (int node = 1; node <= v; node++) {
            if (scc_id[node] == i) scc_list[i].push_back(node);
        }
        sort(scc_list[i].begin(), scc_list[i].end());
    }
    sort(scc_list.begin(), scc_list.end(), [](const vector<int>& a, const vector<int>& b) {
        return a[0] < b[0];
    });

    cout << scc_count << '\n';
    for (int i = 0; i < scc_count; i++) {
        for (const int &u : scc_list[i]) {
            cout << u << " ";
        }
        cout << "-1\n";
    }

    return 0;
}