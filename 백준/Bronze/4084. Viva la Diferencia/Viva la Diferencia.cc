#include <iostream>

using namespace std;

int sub_(const int a, const int b) {
    if (a > b) return a - b;
    else return b - a;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int a, b, c, d;
    while (1) {
        cin >> a >> b >> c >> d;
        if (a == 0 && b == 0 && c == 0 && d == 0) break;
        int cnt = 0;
        while (!(a==b && b==c && c==d && d==a)) {
            int tempa = sub_(a,b);
            int tempb = sub_(b,c);
            int tempc = sub_(c,d);
            int tempd = sub_(d,a);
            a = tempa;
            b = tempb;
            c = tempc;
            d = tempd;
            cnt++;
        }
        cout << cnt << '\n';
    }
    return 0;
}