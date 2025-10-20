#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int n;
  cin >> n;

  vector<short> fruits(n);
  map<short, int> fruit_count;
  int len = 0;
  for (int i = 0; i < n; i++) cin >> fruits[i];

  int left = 0, max_length = 0;
  for (int right = 0; right < n; right++) {
    fruit_count[fruits[right]]++;

    while (fruit_count.size() > 2) {
      fruit_count[fruits[left]]--;
      if (fruit_count[fruits[left]] == 0) {
        fruit_count.erase(fruits[left]);
      }
      left++;
    }

    max_length = max(max_length, right - left + 1);
  }

  cout << max_length << endl;
  return 0;
}