#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, d;
    while (1) {
        cin >> n >> d;
        if (n == 0 && d == 0) break;

        vector<bool> isall(n, 1);
        for (int k = 0; k < d; k++) {
            for (int i = 0; i < n; i++) {
                bool tmp;
                cin >> tmp;
                isall[i] = (isall[i] & tmp);
            }
        }
        bool result = 0;
        for (int i = 0; i < n; i++) result = (result | isall[i]);
        cout << (result?"yes\n":"no\n");
    }
    return 0;
}