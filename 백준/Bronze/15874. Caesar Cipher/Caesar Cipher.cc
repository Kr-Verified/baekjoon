#include <iostream>
#include <string>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, l;
    cin >> n >> l;
    string input;
    cin.ignore();
    getline(cin, input);
    n = n %26;

    for (int i = 0; i < input.size(); i++) {
        if (input[i] >= 'A' && input[i] <= 'Z') cout << (char)((input[i]-'A'+n)%26+'A');
        else if (input[i] >= 'a' && input[i] <= 'z') cout << (char)((input[i]-'a'+n)%26+'a');
        else cout << input[i];
    }

    cout << '\n';
    return 0;
}