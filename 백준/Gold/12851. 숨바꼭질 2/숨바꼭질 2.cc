#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int a, b, ridx=1000000;
    cin >> a >> b;

    queue<pair<int, int>> q;
    vector<int> dist(100001, -1);
    vector<int> cnt(100001, 0);
    q.push({0,a});
    dist[a] = 0;
    cnt[a] = 1;
    while (!q.empty()) {
        int idx = q.front().first;
        int x = q.front().second;
        q.pop();

        if (idx > ridx) continue;
        if (x == b) ridx = min(idx, ridx);

        if (x > 0) {
            if (dist[x-1] == -1) {
                q.push({idx+1,x-1});
                dist[x-1] = dist[x] + 1;
                cnt[x-1] = cnt[x];
            }else if (dist[x-1] == dist[x]+1) cnt[x-1] += cnt[x];
        }
        if (x < b) {
            if (dist[x+1] == -1) {
                q.push({idx+1,x+1});
                dist[x+1] = dist[x] + 1;
                cnt[x+1] = cnt[x];
            }else if (dist[x+1] == dist[x]+1) cnt[x+1] += cnt[x];
        }
        if (2*x <= 100000) {
            if (dist[2*x] == -1) {
                q.push({idx+1,x*2});
                dist[2*x] = dist[x] + 1;
                cnt[2*x] = cnt[x];
            }else if (dist[2*x] == dist[x]+1) cnt[2*x] += cnt[x];
        }
    }

    cout << ridx << '\n' << cnt[b] << '\n';

    return 0;
}