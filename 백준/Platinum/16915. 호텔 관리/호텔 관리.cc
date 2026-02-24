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

    for (const auto& v: g[u]) {
        if (dfn[v] == 0) {
            dfs(v, g, dfn, low, scc_id, on_stack);
            low[u] = min(low[u], low[v]);
        }else if (on_stack[v]) low[u] = min(low[u], dfn[v]);
    }

    if (dfn[u] == low[u]) {
        while (true) {
            const int v = _stack.top();
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

    vector<vector<int>> g(2*(m+1)), room_to_switches(n+1);
    vector<int> state(n+1);
    vector<int> dfn(2*(m+1), 0), low(2*(m+1), 0), scc_id(2*(m+1), -1);
    vector<bool> on_stack(2*(m+1), false);

    for (int i = 1; i <= n; i++) cin >> state[i];

    for (int i = 1; i <= m; i++) {
        int num;
        cin >> num;
        for (int j = 1; j <= num; j++) {
            int number;
            cin >> number;
            room_to_switches[number].push_back(i);
        }
    }

    for (int i = 1; i <= n; i++) {
        int u = room_to_switches[i][0];
        int v = room_to_switches[i][1];

        if (state[i] == 1) {
            g[2*u].push_back(2*v);
            g[2*v].push_back(2*u);
            g[2*u+1].push_back(2*v+1);
            g[2*v+1].push_back(2*u+1);
        }else {
            g[2*u].push_back(2*v+1);
            g[2*v].push_back(2*u+1);
            g[2*u+1].push_back(2*v);
            g[2*v+1].push_back(2*u);
        }
    }

    for (int i = 1; i <= 2*m+1; i++) if (dfn[i] == 0) dfs(i, g, dfn, low, scc_id, on_stack);

    bool possible = true;
    for (int i = 1; i <= m; i++) {
        if (scc_id[2*i] == scc_id[2*i+1]) {
            possible = false;
            break;
        }
    }

    cout << (possible?1:0) << '\n';

    return 0;
}