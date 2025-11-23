#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<double> p(10);

    for (int i = 0; i < 10; i++) {
        cin >> p[i];
    }

    sort(p.begin(), p.end(), greater<double>());

    double result = 1.0;

    for (int x = 1; x <= 9; x++) {
        result *= p[x - 1] / x;
    }

    cout << fixed << setprecision(10) << result * 1e9 << '\n';
    return 0;
}
