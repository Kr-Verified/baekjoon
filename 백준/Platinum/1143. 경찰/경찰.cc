#include <iostream>
#include <stack>
#include <vector>
#include <string>
#include <algorithm>
#include <iomanip>

using namespace std;

int order, scc_count;
stack<int> _stack;

void dfs(int u, vector<vector<int>>& graph, vector<int>& dfn, vector<int>& low, vector<int>& scc_id, vector<bool>& on_stack) {
    dfn[u] = low[u] = ++order;
    on_stack[u] = true;
    _stack.push(u);

    for (const auto& v: graph[u]) {
        if (dfn[v] == 0) {
            dfs(v, graph, dfn, low, scc_id, on_stack);
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

    int n;
    cin >> n;
    vector<int> prices(n), dfn(n, 0), low(n, 0), scc_id(n, -1);
    vector<vector<int>> graph(n);
    vector<bool> on_stack(n, false);
    for (int i = 0; i < n; i++) cin >> prices[i];
    string a;
    for (int i = 0; i < n; i++) {
        cin >> a;
        for (int j = 0; j < n; j++) if (a[j] == 'Y') graph[i].push_back(j);
    }

    for (int u = 0; u < n; u++) if (dfn[u] == 0) dfs(u, graph, dfn, low, scc_id, on_stack);

    vector<vector<int>> scc_graph(scc_count);
    vector<int> indegs(scc_count, 0);
    vector<int> mins(scc_count, 1000);
    vector<bool> checks(scc_count, false);
    for (int u = 0; u < n; u++) {
        if (mins[scc_id[u]] > prices[u]) mins[scc_id[u]] = prices[u];
        for (const auto& v : graph[u]) {
            if (scc_id[u] != scc_id[v]) scc_graph[scc_id[u]].push_back(scc_id[v]);
        }
    }
    for (int u = 0; u < scc_count; u++) {
        sort(scc_graph[u].begin(), scc_graph[u].end());
        scc_graph[u].erase(unique(scc_graph[u].begin(), scc_graph[u].end()), scc_graph[u].end());
        for (const auto& v : scc_graph[u]) indegs[v]++;
    }

    int count = 0, value = 0;
    vector<int> q;
    for (int i = 0; i < scc_count; i++) {
        if (indegs[i] == 0) {
            value += mins[i];
            count++;
        }
    }

    for (int i = 0; i < n; i++) {
        if (!(indegs[scc_id[i]] == 0 && prices[i] == mins[scc_id[i]] && !checks[scc_id[i]])) q.push_back(prices[i]);
        else checks[scc_id[i]] = true;
    }

    sort(q.begin(), q.end());

    for (const auto& nv : q) {
        double x = (double)value/count;
        if (x > (double)(value + nv)/(count+1)) {
            value += nv;
            count++;
        }else break;
    }

    cout << fixed << setprecision(15) << (double)value/count << '\n';

    return 0;
}