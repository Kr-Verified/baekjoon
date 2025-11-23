#include <iostream>
#include <string>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        long long n, a;
        cin >> n >> a;

        string s = "";
        long long x = n;
        while (x > 0) {
            int d = x % a;
            s += (d < 10 ? char('0' + d) : char('A' + (d - 10)));
            x /= a;
        }

        bool ok = true;
        int len = s.size();
        for (int i = 0; i < len / 2; i++) {
            if (s[i] != s[len - 1 - i]) {
                ok = false;
                break;
            }
        }

        cout << (ok ? 1 : 0) << "\n";
    }
}
