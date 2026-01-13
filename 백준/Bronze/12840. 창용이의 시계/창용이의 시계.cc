#include <iostream>
#define DAY 86400

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int h, m, s, cur=0;
    cin >> h >> m >> s;

    cur += h*3600 + m*60 + s;

    int n;
    cin >> n;
    while (n--) {
        int t, number;
        cin >> t;
        if (t==3) cout << cur/3600 << ' ' << (cur%3600)/60 << ' ' << cur%60 << '\n';
        else {
            cin >> number;
            if (t==1) cur = (cur + number) % DAY;
            else if (t==2) {
                cur = (cur - number) % DAY;
                if (cur < 0) cur += DAY;
            }
        }
    }
    
    return 0;
}