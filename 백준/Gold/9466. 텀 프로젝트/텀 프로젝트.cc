#include <iostream>
#include <queue>
#include <vector>

using namespace std;

void dfs(int u, vector<int>& students, vector<int>& visited, vector<bool>& is_team) {
    visited[u] = 1;
    int v = students[u];

    if (visited[v] == 0) {
        dfs(v, students, visited, is_team);
    }else if (visited[v] == 1) {
        int cur = v;
        do {
            is_team[cur] = true;
            cur = students[cur];
        }while (cur != v);
    }

    visited[u] = 2;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> students(n+1);
        vector<int> visited(n+1, 0);
        vector<bool> is_team(n+1, false);
        for (int i = 1; i <= n; i++) cin >> students[i];
        for (int u = 1; u <= n; u++) if (visited[u] == 0) dfs(u, students, visited, is_team);
        int result = 0;
        for (int i = 1; i <= n; i++) if (!is_team[i]) result++;
        cout << result << '\n';
    }
    return 0;
}