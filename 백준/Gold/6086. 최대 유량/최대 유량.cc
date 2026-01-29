#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
#define MAX 1000000

using namespace std;

int edmonds_karp(vector<vector<int>>& graph, int source, int sink) {
    int n = graph.size();
    vector<vector<int>> flow_map(n, vector<int>(n, 0));
    int total_flow = 0;

    while (true) {
        vector<int> parent(n, -1);
        deque<int> queue;
        queue.push_back(source);

        while (!queue.empty()) {
            int u = queue.front();
            queue.pop_front();
            for (int v = 0; v < n; v++) {
                if (parent[v] == -1 && graph[u][v]-flow_map[u][v] > 0) {
                    parent[v] = u;
                    queue.push_back(v);
                }
            }
        }
        if (parent[sink] == -1) break;

        int path_flow = MAX;
        int s = sink;
        while (s != source) {
            path_flow = min(path_flow, graph[parent[s]][s] - flow_map[parent[s]][s]);
            s = parent[s];
        }

        int v = sink;
        while (v != source) {
            int u = parent[v];
            flow_map[u][v] += path_flow;
            flow_map[v][u] -= path_flow;
            v = parent[v];
        }
        total_flow += path_flow;
    }
    return total_flow;
}

int get_idx(char c) {
    if (c >= 'A' && c <= 'Z') return c - 'A';
    if (c >= 'a' && c <= 'z') return c - 'a' + 26;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;
    vector<vector<int>> graph(52, vector<int>(52, 0));
    for (int i = 0; i < n; i++) {
        char u, v;
        int cap;
        cin >> u >> v >> cap;
        graph[get_idx(u)][get_idx(v)] += cap;
        graph[get_idx(v)][get_idx(u)] += cap;
    }

    int total_flow = edmonds_karp(graph, get_idx('A'), get_idx('Z'));
    cout << total_flow << '\n';

    return 0;
}