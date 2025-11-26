#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;

    vector<int> plan(n);
    vector<int> act(n);

    for (int i = 0; i < n; i++) cin >> plan[i];
    for (int i = 0; i < n; i++) cin >> act[i];

    int cnt = 0;
    for (int i = 0; i < n; i++) {
        if (plan[i] <= act[i]) cnt++;
    }

    cout << cnt << endl;

    return 0;
}