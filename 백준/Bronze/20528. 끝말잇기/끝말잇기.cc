#include <iostream>
#include <string>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;
    char pre;
    string temp;

    cin >> temp;
    pre = temp[0];
    n--;
    while (n--) {
        string s;
        cin >> s;
        if ((char)(s[0]) != pre) {
            cout << 0 << '\n';
            return 0;
        }
    }
    cout << 1 << '\n';
    return 0;
}