#include <iostream>

using namespace std;

int main() {
    long long a1, a2, b1, b2, c1, c2, c3;
    
    cin >> a1 >> a2;
    cin >> b1 >> b2;
    cin >> c1 >> c2 >> c3;
    
    cout << (a1*a2 + b1*b2)*c1*c2*c3;
    
    return 0;
}