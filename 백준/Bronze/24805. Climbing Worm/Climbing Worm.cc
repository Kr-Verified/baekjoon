#include <iostream>

using namespace std;

int main() {
    int a, b, c;

    cin >> a >> b >> c;

    c -= b;
    if (c<1) cout << "1\n";
    else cout << c/(a-b)+(c%(a-b)==0?0:1) << '\n';
    
    return 0;
}