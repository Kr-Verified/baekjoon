#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int cnt = -1;
  string s;
  for (int i = 0; i < 3; i++) {
    cin >> s;
    if (!(s == "Fizz" || s == "Buzz" || s == "FizzBuzz")) {
      cnt = stoi(s);
    }
    if (cnt != -1) cnt++;
  }

  if (cnt % 3 == 0 && cnt % 5 == 0) cout << "FizzBuzz" << '\n';
  else if (cnt % 3 == 0 && cnt % 5 != 0) cout << "Fizz" << '\n';
  else if (cnt % 3 != 0 && cnt % 5 == 0) cout << "Buzz" << '\n';
  else cout << cnt << '\n';

  return 0;
}