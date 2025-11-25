#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int price, work, my;
    cin >> price >> work >> my;

    int val = work / price;

    cout << my * val * 3 << '\n';
    return 0;
}