#include <iostream>

using namespace std;

int main() {
    int a, min = 100, sum = 0;

    for (int i = 0; i < 7; i++) {
        cin >> a;
        if (a&1) {
            if (a < min) min = a;
            sum += a;
        }
    }

    if (min == 100 & sum == 0) {
      cout << -1 << '\n';
      return 0;
    }
    cout << sum << '\n' << min << '\n';
    return 0;
}