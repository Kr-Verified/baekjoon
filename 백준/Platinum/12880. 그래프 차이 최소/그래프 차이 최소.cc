#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

int order, scc_count;

void dfs(int u, vector<vector<pair<int, int>>>& edges, vector<int>& dfn, vector<int>& low, vector<int>& scc_id, vector<bool>& on_stack, stack<int>& _stack, int left, int right) {
    dfn[u] = low[u] = ++order;
    on_stack[u] = true;
    _stack.push(u);

    for (const auto& [v, weight] : edges[u]) {
        if (weight >= left && weight <= right) {
            if (dfn[v] == 0) {
                dfs(v, edges, dfn, low, scc_id, on_stack, _stack, left, right);
                low[u] = min(low[u], low[v]);
            }else if (on_stack[v]) low[u] = min(low[u], dfn[v]);
        }
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

    vector<vector<pair<int, int>>> edges(n);
    vector<int> weights;

    for (int u = 0; u < n; u++) {
        for (int v = 0; v < n; v++) {
            int weight;
            cin >> weight;
            if (u == v) continue;
            edges[u].push_back({v, weight});
            weights.push_back(weight);
        }
    }

    sort(weights.begin(), weights.end());
    weights.erase(unique(weights.begin(), weights.end()), weights.end());

    int left = 0, min_v = 150000;
    for (int right = 0; right < weights.size(); right++) {
        while (left <= right) {
            order = scc_count = 0;
            vector<int> dfn(n, 0), low(n, 0), scc_id(n, -1);
            vector<bool> on_stack(n, false);
            stack<int> _stack;
            for (int u = 0; u < n; u++) if (dfn[u] == 0) dfs(u, edges, dfn, low, scc_id, on_stack, _stack, weights[left], weights[right]); // edges
            if (scc_count == 1) {
                min_v = min(min_v, (weights[right] - weights[left]));
                left++;
            }else break;
        }
    }

    cout << (n==1? 0: min_v) << '\n';

    return 0;
}