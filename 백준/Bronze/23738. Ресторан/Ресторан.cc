#include <iostream>
#include <string>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    string input;
    cin >> input;
    for (int i = 0; i < input.size(); i++) {
        char ch = input[i];
        if (ch == 'B') cout << 'v';
        else if (ch == 'E') cout << "ye";
        else if (ch == 'H') cout << 'n';
        else if (ch == 'P') cout << 'r';
        else if (ch == 'C') cout << 's';
        else if (ch == 'Y') cout << 'u';
        else if (ch == 'X') cout << 'h';
        else cout << (char)(ch+32);
    }

    cout << '\n';
    
    return 0;
}