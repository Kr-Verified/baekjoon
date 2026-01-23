#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

int order = 0, scc_count = 0;
stack<int> _stack;

void dfs(int u, vector<vector<int>>& g, vector<int>& dfn, vector<int>& low, vector<int>& scc_id, vector<bool>& on_stack) {
    dfn[u] = low[u] = ++order;
    on_stack[u] = true;
    _stack.push(u);

    for (const auto &v : g[u]) {
        if (dfn[v] == 0) {
            dfs(v, g, dfn, low, scc_id, on_stack);
            low[u] = min(low[u], low[v]);
        }else if (on_stack[v]) {
            low[u] = min(low[u], dfn[v]);
        }
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
    next:
        while (t--) {
            order = 0, scc_count = 0;
            _stack = stack<int>();
            int n, m;
            cin >> n >> m;

            vector<vector<int>> g(n);
            vector<int> dfn(n, 0), low(n, 0), scc_id(n, -1);
            vector<bool> on_stack(n, false);

            for (int i = 0; i < m; i++) {
                int u, v;
                cin >> u >> v;
                g[u].push_back(v);
            }

            for (int i = 0; i < n; i++) if (dfn[i] == 0) dfs(i, g, dfn, low, scc_id, on_stack);

            vector<int> indeg(scc_count, 0);
            for (int u = 0; u < n; u++) {
                for (const auto &v : g[u]) if (scc_id[u] != scc_id[v]) indeg[scc_id[v]]++;
            }

            int start_scc = -1;
            for (int i = 0; i < scc_count; i++) {
                if (indeg[i] == 0) {
                    if (start_scc != -1) {
                        cout << "Confused\n\n";
                        goto next;
                    }
                    start_scc = i;
                }
            }

            if (start_scc == -1) cout << "Confused\n";
            else {
                for (int i = 0; i < n; i++) {
                    if (scc_id[i] == start_scc) cout << i << '\n';
                }
            }
            cout << '\n';
        }
    return 0;
}