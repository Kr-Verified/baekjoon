#include <iostream>
#include <string>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    int t;
    cin >> t;

    while (t--) {
        string input;
        cin >> input;

        char a, b;
        bool flag = false;
        if (input.size() == 7) {
            a = input[0];
            b = input[2];

            if (a != b && input[1]==a && input[3]==b && input[4]==a && input[5]==b && input[6]==b) {
                flag = true;
            }
        }
        cout << (flag?"1\n":"0\n");
    }
    return 0;
}