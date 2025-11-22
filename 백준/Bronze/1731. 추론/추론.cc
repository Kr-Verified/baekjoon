#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;

    long long a, b, c;
    cin >> a >> b >> c;

    long long last = c;
    if (b-a == c-b) {
        for (int i = 3; i < n; i++) cin >> last;
        cout << last+b-a;
    }else {
        for (int i = 3; i < n; i++) cin >> last;
        long long diff = b/a;
        cout << last*diff;
    }

    return 0;
}