#include <iostream>

using namespace std;

int main() {
  long long a, b;
  cin >> a >> b;
  long long result = a-b;
  cout << (result > 0? result:-result);

  return 0;
}