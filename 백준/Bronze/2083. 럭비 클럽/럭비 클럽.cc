#include <iostream>
#include <string>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  string name;
  int age, weigh;

  while (true) {
    cin >> name >> age >> weigh;
    if (name == "#" && age == 0 && weigh == 0) break;
    cout << name << " " << (age > 17 || weigh >= 80 ? "Senior":"Junior") << '\n';
  }

  return 0;
}