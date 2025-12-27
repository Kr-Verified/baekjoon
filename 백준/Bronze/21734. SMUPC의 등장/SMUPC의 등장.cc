#include <iostream>
#include <string>

using namespace std;

int main() {
    string input;
    cin >> input;

    for (char ch : input) {
        int num = ch, sum = 0;
        while (num > 0) {
            sum += num%10;
            num /= 10;
        }
        for (int j = 0; j < sum; j++) cout << ch;
        cout << '\n';
    }
    
    return 0;
}