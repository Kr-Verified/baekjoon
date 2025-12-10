#include <iostream>

using namespace std;

int main() {
    int a, d, k;
    cin >> a >> d >> k;

    if ((k-a)%d == 0) {
        int n = (k-a)/d + 1;
        if (n >= 1) {
            cout << n << '\n';
            return 0;
        }
    }

    cout << "X\n";
    return 0;
}