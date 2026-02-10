#include <iostream>
#include <stack>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

int order, scc_count;
stack<int> _stack;

void dfs(const int u, vector<vector<int>>& g, vector<int>& scc_id, vector<bool>& on_stack, vector<int>& dfn, vector<int>& low) {
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

    int n, r, l;
    cin >> n >> r >> l;

    vector<pair<int, int>> bulb(l);
    vector<vector<int>> g(2*l);
    vector<int> dfn(2*l, 0), low(2*l, 0), scc_id(2*l, -1);
    vector<bool> on_stack(2*l, false);

    for (int i = 0; i < l; i++) cin >> bulb[i].first >> bulb[i].second;

    for (int i = 0; i < l; i++) for (int j = i+1; j < l; j++) {
        const int ir = bulb[i].first, ic = bulb[i].second, jr = bulb[j].first, jc = bulb[j].second;
        if (ir == jr && abs(ic - jc) <= 2*r) {
            g[2*i].push_back(2*j^1);
            g[2*j].push_back(2*i^1);
        }
        if (ic == jc && abs(ir - jr) <= 2*r) {
            g[2*i^1].push_back(2*j);
            g[2*j^1].push_back(2*i);
        }
    }

    for (int u = 0; u < 2*l; u++) if (dfn[u] == 0) dfs(u, g, scc_id, on_stack, dfn, low);

    bool is_possible = true;
    for (int i = 0; i < l; i++) {
        if (scc_id[2*i] == scc_id[2*i+1]) {
            is_possible = false;
            break;
        }
    }

    cout << (is_possible ? 1 : 0) << '\n';

    return 0;
}