#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

int order = 0, scc_count = 0;
stack<int> _stack;

void dfs(int u, vector<vector<int>>& g, vector<int>& dfn, vector<bool>& on_stack, vector<int>& scc_id, vector<int>& low) {
    dfn[u] = low[u] = ++order;
    on_stack[u] = true;
    _stack.push(u);

    for (const auto& v : g[u]) {
        if (dfn[v] == 0) {
            dfs(v, g, dfn, on_stack, scc_id, low);
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

    while (true) {
        order = scc_count = 0;
        int n;
        cin >> n;
        if (n == 0) break;

        vector<vector<int>> g(26);
        vector<int> dfn(26, 0), low(26, 0), scc_id(26, -1);
        vector<bool> on_stack(26, false), used(26, false);

        for (int i = 0; i < n; i++) {
            vector<char> v(5);
            char u;
            for (int j = 0; j < 5; j++) {
                cin >> v[j];
                used[v[j]-'A'] = true;
            }
            cin >> u;
            used[u-'A'] = true;
            for (int j = 0; j < 5; j++) g[u-'A'].push_back(v[j]-'A');
        }

        for (int i = 0; i < 26; i++) if (used[i] && dfn[i] == 0) dfs(i, g, dfn, on_stack, scc_id, low);

        vector<vector<int>> dag(scc_count);
        for (int i = 0; i < 26; i++) {
            if (scc_id[i] != -1) dag[scc_id[i]].push_back(i);
        }
        for (auto& d : dag) sort(d.begin(), d.end());
        sort(dag.begin(), dag.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[0] < b[0];
        });

        for (const auto& dag_list : dag) {
            for (const auto& d : dag_list) {
                cout << (char)(d+'A') << " ";
            }
            cout << '\n';
        }
        cout << '\n';
    }
    return 0;
}