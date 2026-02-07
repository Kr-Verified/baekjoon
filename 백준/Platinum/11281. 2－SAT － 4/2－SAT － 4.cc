#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>

using namespace std;

int order, scc_count;
stack<int> _stack;

int get(const int n) {
    return n > 0 ? 2*(n-1) : 2*(-n-1)+1;
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
    vector<int> dfn(2*n, 0), low(2*n, 0), scc_id(2*n, -1);
    vector<bool> on_stack(2*n, false);

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;

        u = get(u), v = get(v);

        g[u^1].push_back(v);
        g[v^1].push_back(u);
    }

    for (int u = 0; u < 2*n; u++) if (dfn[u] == 0) dfs(u, g, scc_id, on_stack, dfn, low);

    bool is_possible = true;
    for (int i = 0; i < n; i++) {
        if (scc_id[i*2] == scc_id[i*2+1]) {
            is_possible = false;
            break;
        }
    }

    if (!is_possible) cout << "0\n";
    else {
        cout << "1\n";
        for (int i = 0; i < n; i++) {
            if (scc_id[i*2] < scc_id[i*2+1]) cout << "1 ";
            else cout << "0 ";
        }
        cout << "\n";
    }

    return 0;
}