#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, input;
    cin >> n;

    while (n--) {
        cin >> input;
        cout << ((input+1)%(input%100)==0?"Good":"Bye") << '\n';
    }
    return 0;
}