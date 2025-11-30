#include <iostream>
#include <string>

using namespace std;

const string digits = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz-_";

bool isPalindrome(int value) {
    bool finaltmp = 0;
    for (int i = 2; i <= 64; i++) {
        string result = "";
        int tmpvalue = value;
        while (tmpvalue > 0) {
            result = digits[tmpvalue%i] + result;
            tmpvalue /= i;
        }
        bool tmp = 1;
        for (int i = 0; i < result.length()/2; i++) {
            tmp = tmp & (result[i]==result[result.length()-i-1]);
        }
        finaltmp = finaltmp | tmp;
    }
    return finaltmp;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t, input;
    cin >> t;
    while (t--) {
        cin >> input;
        cout << isPalindrome(input) << '\n';
    }
    
    return 0;
}