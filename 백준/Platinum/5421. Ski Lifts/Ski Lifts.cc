#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

int order, scc_count;
int dr[4] = {-1, 0, 1, 0};
int dc[4] = {0, 1, 0, -1};

void dfs(int u, vector<vector<int>>& g, vector<int>& dfn, vector<int>& low, vector<int>& scc_id, vector<bool>& on_stack, stack<int>& _stack) {
    dfn[u] = low[u] = ++order;
    on_stack[u] = true;
    _stack.push(u);

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
        int n, m;
        cin >> n >> m;
        vector<vector<int>> g(n*m), H(n, vector<int>(m, 0));
        vector<int> dfn(n*m, 0), low(n*m, 0), scc_id(n*m, -1);
        vector<bool> on_stack(n*m, false);
        stack<int> _stack;

        for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) cin >> H[i][j];
        for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) {
            int u = i*m+j;
            for (int d = 0; d < 4; d++) {
                int nr = i+dr[d], nc = j+dc[d];
                if (nr < 0 || nr >= n || nc < 0 || nc >= m) continue;
                int v = nr*m+nc;
                if (H[i][j] > H[nr][nc]) g[u].push_back(v);
                else if (H[i][j] < H[nr][nc]) g[v].push_back(u);
                else {
                    g[u].push_back(v);
                    g[v].push_back(u);
                }
            }
        }

        for (int u = 0; u < n*m; u++) if (dfn[u] == 0) dfs(u, g, dfn, low, scc_id, on_stack, _stack);

        vector<vector<int>> scc_g(scc_count);
        for (int i = 0; i < n*m; i++) for (const auto& v: g[i]) if (scc_id[i] != scc_id[v]) {
            int ur = i/m, uc = i%m, vr = v/m, vc = v%m;
            if (H[ur][uc] > H[vr][vc]) scc_g[scc_id[i]].push_back(scc_id[v]);
            else if (H[ur][uc] < H[vr][vc]) scc_g[scc_id[v]].push_back(scc_id[i]);
            else {
                scc_g[scc_id[i]].push_back(scc_id[v]);
                scc_g[scc_id[v]].push_back(scc_id[i]);
            }
        }
        vector<int> indegs(scc_count, 0), outdegs(scc_count, 0);
        for (int i = 0; i < scc_count; i++) {
            sort(scc_g[i].begin(), scc_g[i].end());
            scc_g[i].erase(unique(scc_g[i].begin(), scc_g[i].end()), scc_g[i].end());
            for (const auto& v: scc_g[i]) {
                indegs[v]++;
                outdegs[i]++;
            }
        }
        int zero_indeg = 0, zero_outdeg = 0;
        for (int i = 0; i < scc_count; i++) {
            if (indegs[i] == 0) zero_indeg++;
            if (outdegs[i] == 0) zero_outdeg++;
        }
        cout << (scc_count == 1? 0:max(zero_indeg, zero_outdeg)) << '\n';
    }

    return 0;
}