#include <iostream>
#include <stack>
#include <algorithm>
#include <vector>

using namespace std;

int next_list[200001], scc_id[200001], dfn[200001], low[200001], dp[200001], order=0, scc_count=0;
bool on_stack[200001]={false};
stack<int> _stack;

void dfs(int u) {
    dfn[u] = low[u] = ++order;
    on_stack[u] = true;
    _stack.push(u);

    int v = next_list[u];
    if (dfn[v] == 0) {
        dfs(v);
        low[u] = min(low[u], low[v]);
    }else if (on_stack[v]) {
        low[u] = min(low[u], dfn[v]);
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

int solve(int gid, const vector<int> &scc_size, const vector<int> &representative) {
    if (dp[gid] != 0) return dp[gid];

    int u = representative[gid];
    int v = next_list[u];
    int next_gid = scc_id[v];

    dp[gid] = scc_size[gid];

    if (gid != next_gid) {
        dp[gid] += solve(next_gid, scc_size, representative);
    }

    return dp[gid];
}

int create_next(int n, int max) {
    int result = n;
    while (n > 0) {
        result += n % 10;
        n /= 10;
    }
    while (result > max) result -= max;
    return result;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;

    for (int i = 1; i <= n; i++) {
        next_list[i] = create_next(i, n);
    }
    for (int i = 1; i <= n; i++) if (dfn[i] == 0) dfs(i);

    vector<int> scc_size(scc_count, 0), representative(scc_count);
    for (int i = 1; i <= n; i++) {
        scc_size[scc_id[i]]++;
        representative[scc_id[i]] = i;
    }

    int result = 0;
    for (int i = 0; i < scc_count; i++) result = max(result, solve(i, scc_size, representative));

    cout << result << endl;

    return 0;
}