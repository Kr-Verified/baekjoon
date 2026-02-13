#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>

using namespace std;

int order, scc_count;

void dfs(const int u, vector<vector<int>>& g, vector<int>& dfn, vector<int>& low, vector<int>& scc_id, vector<bool>& on_stack, stack<int>& _stack) {
    dfn[u] = low[u] = ++order;
    _stack.push(u);
    on_stack[u] = true;

    for (const auto& v: g[u]) {
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

    int t;
    cin >> t;
    while (t--) {
        order = scc_count = 0;
        int n, m, k;
        cin >> n >> m >> k;

        vector<vector<int>> g(2*(n+m));
        vector<int> dfn(2*(n+m), 0), low(2*(n+m), 0), scc_id(2*(n+m), 0);
        vector<bool> on_stack(2*(n+m), false);
        stack<int> _stack;

        auto add_edge = [&](int x, int y) {
            g[x^1].push_back(y);
            g[y^1].push_back(x);
        };

        auto get_ver = [&](int idx, bool is_down) {
            int id = idx - 1;
            return is_down ? (2*id) : (2*id + 1);
        };

        auto get_hor = [&](int idx, bool is_right) {
            int id = m + idx - 1;
            return is_right ? (2*id) : (2*id + 1);
        };

        for (int i = 0; i < k; i++) {
            int ax, ay, bx, by;
            cin >> ax >> ay >> bx >> by;
            if (ax == bx && ay == by) continue;
            if (ax == bx) {
                int p = get_hor(ax, ay < by);
                add_edge(p, p);
            }else if (ay == by) {
                int p = get_ver(ay, ax < bx);
                add_edge(p, p);
            }else {
                int ar = get_hor(ax, ay < by);
                int bc = get_ver(by, ax < bx);

                int ac = get_ver(ay, ax < bx);
                int br = get_hor(bx, ay < by);
                add_edge(ar, ac);
                add_edge(ar, br);
                add_edge(bc, ac);
                add_edge(bc, br);
            }
        }

        for (int u = 0; u < 2*(n+m); u++) if (dfn[u] == 0) dfs(u, g, dfn, low, scc_id, on_stack, _stack);

        bool is_possible = true;
        for (int u = 0; u < n+m; u++) {
            if (scc_id[2*u] == scc_id[2*u+1]) {
                is_possible = false;
                break;
            }
        }

        cout << (is_possible ? "Yes" : "No") << '\n';
    }

    return 0;
}