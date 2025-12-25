#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main() {
    int n;
    cin >> n;

    long double result = 0, input;
    for (int i = 0; i < n; i++) {
        cin >> input;
        result += input*input*input;
    }

    cout << fixed << setprecision(8);
    cout << pow(result, 1.0/3) << '\n';
    
    return 0;
}