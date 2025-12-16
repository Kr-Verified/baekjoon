#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int a, b, c;
        cin >> a >> b >> c;
        if (a+b==c || a-b==c || a*b==c || (a/b==c && a%b==0) || b-a==c || (b/a==c && b%a==0)) cout << "Possible\n";
        else cout << "Impossible\n";
    }

    return 0;
}