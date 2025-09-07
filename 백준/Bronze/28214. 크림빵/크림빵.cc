#include <iostream>

using namespace std;

int main() {
    int n, k, p, result = 0;
    cin >> n >> k >> p;

    while (n--) {
        int cnt = 0;
        for (int i = 0; i < k; i++) {
            int x;
            cin >> x;
            cnt += 1-x;
        }
        if (cnt < p) result++;
    }

    cout << result << endl;

    return 0;
}