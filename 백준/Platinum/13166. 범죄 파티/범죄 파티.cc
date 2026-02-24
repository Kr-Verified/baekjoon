#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>

using namespace std;

int order, scc_count;

typedef struct Info {
    int friend_id;
    int limit;
} Info;

typedef struct Connection {
    int suspect_id;
    int order;
} Connection;

vector<vector<Info>> suspects(200001);
vector<Connection> friend_to_suspects[400001];

int get(vector<vector<Info>>& suspectsList, const int k, const int i) {
    if (k >= suspectsList[i][0].limit && k >= suspectsList[i][1].limit) return 3;
    if (k >= suspectsList[i][0].limit) return 2;
    if (k >= suspectsList[i][1].limit) return 1;
    return 0;
}

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

    int n;
    cin >> n;

    for (int i = 1; i <= n; i++) {
        int a, ka, b, kb;
        cin >> a >> ka >> b >> kb;

        suspects[i] = {{a, ka}, {b, kb}};

        friend_to_suspects[a].push_back({i, 0});
        friend_to_suspects[b].push_back({i, 1});
    }

    int low = 0, high = 1000000, answer = -1;
    while (low <= high) {
        int mid = low+(high-low)/2;
        order = scc_count = 0;
        vector<vector<int>> g(2*(n+1));
        vector<int> dfn(2*(n+1), 0), _low(2*(n+1), 0), scc_id(2*(n+1), -1);
        vector<bool> on_stack(2*(n+1), false);
        stack<int> _stack;
        bool possible = true;
        for (int i = 1; i <= n; i++) {
            const int menu = get(suspects, mid, i);
            if (menu == 2) { // 0번째 친구만 충족
                g[2*i+1].push_back(2*i);
            }else if (menu == 1) { // 1번째 친구만 충족
                g[2*i].push_back(2*i+1);
            }else if (menu == 0) {
                possible = false;
                break;
            }
        }

        for (int p = 1; p <= 2*n+1; p++) {
            if (friend_to_suspects[p].size() < 2) continue;

            auto& c1 = friend_to_suspects[p][0];
            auto& c2 = friend_to_suspects[p][1];

            if (suspects[c1.suspect_id][c1.order].limit <= mid && suspects[c2.suspect_id][c2.order].limit <= mid) {
                int u = (c1.order == 0) ? 2*c1.suspect_id : 2*c1.suspect_id+1;
                int v = (c2.order == 0) ? 2*c2.suspect_id : 2*c2.suspect_id+1;

                g[u].push_back(v^1);
                g[v].push_back(u^1);
            }
        }

        for (int i = 1; i <= 2*n+1; i++) if (dfn[i] == 0) dfs(i, g, dfn, _low, scc_id, on_stack, _stack);

        for (int i = 1; i <= n; i++) {
            if (scc_id[2*i] == scc_id[2*i+1]) {
                possible = false;
                break;
            }
        }

        if (possible) {
            answer = mid;
            high = mid-1;
        }else {
            low = mid+1;
        }
    }

    cout << answer << '\n';

    return 0;
}