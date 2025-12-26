#include <iostream>
#include <vector>

using namespace std;

long long abs_(long long a) {
  return (a>0?a:-a);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  long long n, temp, result = 0;
  cin >> n;

  vector<long long> input(n);
  temp = n;
  while (temp--) cin >> input[temp];

  for(int i = 0; i < n-1; i++) for(int j = i+1; j < n; j++) {
    result += abs_(input[i]-input[j]);
  }

  cout << result*2 << '\n';

  return 0;
}