#include <iostream>
#include <string>
#include <bitset>
#include <cmath>
using namespace std;

int main() {
    string octal;
    cin >> octal;

    for (int i = 0; i < (int)octal.size(); ++i) {
        int val = octal[i] - '0';
        if (i == 0) {
            cout << bitset<3>(val).to_string().substr(3 - (val == 0 ? 1 : (int)log2(val) + 1));
        } else {
            cout << bitset<3>(val).to_string();
        }
    }
    cout << "\n";
    return 0;
}
