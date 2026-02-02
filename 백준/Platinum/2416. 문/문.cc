#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int order, scc_count;
stack<int> _stack;

void dfs(int u, vector<vector<int>>& g, vector<bool>& on_stack, vector<int>& scc_id, vector<int>& dfn, vector<int>& low) {
    dfn[u] = low[u] = ++order;
    on_stack[u] = true;
    _stack.push(u);

    for (const auto v : g[u]) {
        if (dfn[v] == 0) {
            dfs(v, g, on_stack, scc_id, dfn, low);
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
    vector<vector<int>> g(m*2);
    vector<int> dfn(m*2, 0), low(m*2, 0), scc_id(m*2, -1);
    vector<bool> on_stack(m*2, false);

    for (int i = 0; i < n; i++) {
        int a, sa, b, sb;
        cin >> a >> sa >> b >> sb;
        a--; b--;
        g[a*2+(1-sa)].push_back(b*2+sb);
        g[b*2+(1-sb)].push_back(a*2+sa);
    }

    for (int u = 0; u < 2*m; u++) if (dfn[u] == 0) dfs(u, g, on_stack, scc_id, dfn, low);

    for (int i = 1; i <= m; i++) {
        if (scc_id[(i-1)*2] == scc_id[(i-1)*2+1]) {
            cout << "IMPOSSIBLE\n";
            return 0;
        }
    }

    for (int i = 0; i < m; i++) {
        if (scc_id[i*2] < scc_id[i*2+1]) cout << "0\n";
        else cout << "1\n";
    }

    return 0;
}