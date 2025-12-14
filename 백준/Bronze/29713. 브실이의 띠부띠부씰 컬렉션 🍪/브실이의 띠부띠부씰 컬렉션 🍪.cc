#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
  int n, result = 0;
  vector<int> cnt(26, 0);
  string input;
  string temp = "BRONZESILVER";
  bool flag = true;

  cin >> n;
  cin >> input;
  for (int i = 0; i < input.size(); i++) cnt[input[i]-'A']++;

  while (flag) {
    for (int i = 0; i < temp.size(); i++) {
      if (cnt[temp[i]-'A'] > 0) cnt[temp[i]-'A']--;
      else {
        flag = false;
        break;
      }
    }
    if (flag) result++;
  }

  cout << result << '\n';

  return 0;
}