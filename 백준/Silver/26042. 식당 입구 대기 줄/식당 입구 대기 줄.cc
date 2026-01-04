#include <iostream>
#include <queue>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, mode, num, max=0, min=0;
    queue<int> q;

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> mode;
        if (mode == 2) {if (q.size()>0) q.pop();}
        else {
            cin >> num;
            q.push(num);
            if (max == q.size() && min > 0 && min > q.back()) min = q.back();
            else if (max < q.size()) {
                max = q.size();
                min = q.back();
            }
        }
    }

    cout << max << " " << min << "\n";
    
    return 0;
}