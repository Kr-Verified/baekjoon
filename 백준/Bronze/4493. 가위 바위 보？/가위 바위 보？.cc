#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int result = 0, n;
        cin >> n;
        while (n--) {
            char a, b;
            cin >> a >> b;
            if ((a == 'R' && b == 'S') || (a == 'P' && b == 'R') || (a == 'S' && b == 'P')) result++;
            else if (a != b) result--;
        }
        if (result > 0) cout << "Player 1\n";
        else if (result < 0) cout << "Player 2\n";
        else cout << "TIE\n";
    }

    return 0;
}