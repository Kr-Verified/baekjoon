#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

int order, scc_count;
stack<int> _stack;

void dfs(int u, vector<vector<int>>& g, vector<int>& dfn, vector<int>& scc_id, vector<int>& low, vector<bool>& on_stack) {
    dfn[u] = low[u] = ++order;
    on_stack[u] = true;
    _stack.push(u);

    for (const auto& v : g[u]) {
        if (dfn[v] == 0) {
            dfs(v, g, dfn, scc_id, low, on_stack);
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

    int w, l, dr[4] = {-1, 0, 1, 0}, dc[4] = {0, 1, 0, -1};
    cin >> w >> l;

    vector<vector<int>> H(l, vector<int>(w, 0));
    vector<vector<int>> g(w*l);
    vector<int> dfn(w*l, 0), low(w*l, 0), scc_id(w*l, -1);
    vector<bool> on_stack(w*l, false);
    for (int i = 0; i < l; i++) for (int j = 0; j < w; j++) cin >> H[i][j];
    for (int i = 0; i < l; i++) for (int j = 0; j < w; j++) {
        int u = i * w + j;
        for (int d = 0; d < 4; d++) {
            int nr = i + dr[d];
            int nc = j + dc[d];
            if (nr < 0 || nr >= l || nc < 0 || nc >= w) continue;

            int v = nr * w + nc;
            if (H[i][j] > H[nr][nc]) g[u].push_back(v);
            else if (H[i][j] < H[nr][nc]) g[v].push_back(u);
            else {
                g[u].push_back(v);
                g[v].push_back(u);
            }
        }
    }

    for (int u = 0; u < w*l; u++) if (dfn[u] == 0) dfs(u, g, dfn, scc_id, low, on_stack);

    int answer = 0;
    if (scc_count != 1) {
        vector<int> indeg(scc_count, 0), outdeg(scc_count, 0);
        vector<vector<int>> dag_g(scc_count);
        for (int u = 0; u < w*l; u++) for (const auto& v : g[u]) if (scc_id[u] != scc_id[v]) {
            int r = u/w, c = u%w;
            int nr = v/w, nc = v%w;
            if (H[r][c] > H[nr][nc]) dag_g[scc_id[u]].push_back(scc_id[v]);
            else if (H[r][c] < H[nr][nc]) dag_g[scc_id[v]].push_back(scc_id[u]);
            else {
                dag_g[scc_id[u]].push_back(scc_id[v]);
                dag_g[scc_id[v]].push_back(scc_id[u]);
            }
        }
        for (int i = 0; i < scc_count; i++) {
            sort(dag_g[i].begin(), dag_g[i].end());
            dag_g[i].erase(unique(dag_g[i].begin(), dag_g[i].end()), dag_g[i].end());
            for (const auto& v : dag_g[i]) {
                indeg[v]++;
                outdeg[i]++;
            }
        }
        int zero_indeg = 0, zero_outdeg = 0;
        for (int i = 0; i < scc_count; i++) {
            if (indeg[i] == 0) zero_indeg++;
            if (outdeg[i] == 0) zero_outdeg++;
        }
        answer = max(zero_indeg, zero_outdeg);
    }
    cout << answer << '\n';

    return 0;
}