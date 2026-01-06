#include <iostream>
#include <stack>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    long long n, input;
    cin >> n;
    stack<long long> s;
    for (int i = 0; i < n; i++) {
        cin >> input;
        s.push(input);
    }

    long long up = s.top();
    s.pop();
    long long down = 1;
    while (!s.empty()) {
        long long a = s.top();
        s.pop();
        long long new_up = up*a+down;
        long long new_down = up;

        up = new_up;
        down = new_down;
    }

    cout << up-down<< " " << up << '\n';
    
    return 0;
}