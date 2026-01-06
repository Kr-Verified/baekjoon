#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;
    while (n--) {
        double b, p;
        cin >> b >> p;
        cout << (60*(b-1)/p) << " " << (60*b/p) << " " << (60*(b+1)/p) << '\n';
    }
    
    return 0;
}