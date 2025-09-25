#include <iostream>
#include <string>
#define ll long long
#define M 1234567891

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int n;
  cin >> n;
  string s;
  cin >> s;

  ll sum = 0;
  ll power = 1;
  for (int i = 0; i < s.length(); i++) {
    sum = (sum + (s[i] - 'a' + 1) * power) % M;
    power = (power * 31) % M;
  }

  cout << sum << '\n';
  return 0;
}