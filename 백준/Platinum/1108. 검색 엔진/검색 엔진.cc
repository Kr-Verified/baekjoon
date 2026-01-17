#include <iostream>
#include <stack>
#include <vector>
#include <string>
#include <unordered_map>
#include <set>
#include <algorithm>
#define um unordered_map

using namespace std;

int scc_count = 0, order = 0;
um<string, int> scc_id, dfn, low;
um<string, long long int> result;
um<string, bool> on_stack;
um<string, vector<string>> graph;
stack<string> _stack;
set<string> nodes;

void dfs(string u) {
    dfn[u] = low[u] = ++order;
    on_stack[u] = true;
    _stack.push(u);

    for (const string &v : graph[u]) {
        if (dfn[v] == 0) {
            dfs(v);
            low[u] = min(low[u], low[v]);
        }else if (on_stack[v]) low[u] = min(low[u], dfn[v]);
    }

    if (low[u] == dfn[u]) {
        while (true) {
            string v = _stack.top();
            _stack.pop();
            on_stack[v] = false;
            scc_id[v] = scc_count;
            if (v == u) break;
        }
        scc_count++;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    string target;
    cin >> n;

    for (int i = 0; i < n; i++) {
        string u, v;
        int cnt;
        cin >> u >> cnt;
        nodes.insert(u);
        for (int k = 0; k < cnt; k++) {
            cin >> v;
            graph[v].push_back(u);
            nodes.insert(v);
        }
    }
    cin >> target;

    vector<string> nodes_vector;
    for (const string &u : nodes) {
        nodes_vector.push_back(u);
        result[u] = 1;
        dfn[u] = low[u] = 0;
    }

    for (const string &u : nodes) if (dfn[u] == 0) dfs(u);

    // scc가 독립인 것만 찾기
    // 독립인것만 더하기 (기본값은 result[u] = 1)
    sort(nodes_vector.begin(), nodes_vector.end(), [](const string &a, const string &b) {
        return scc_id[a] > scc_id[b];
    });

    for (const string &u : nodes_vector) {
        for (const string &v : graph[u]) {
            if (scc_id[u] != scc_id[v]) result[v] += result[u];
        }
    }

    cout << result[target] << '\n';

    return 0;
}