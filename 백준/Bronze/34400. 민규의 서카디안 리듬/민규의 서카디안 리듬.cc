#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        cout << ((n % 25 >= 17) ? "OFFLINE" : "ONLINE") << '\n';
    }

    return 0;
}