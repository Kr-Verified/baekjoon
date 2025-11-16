#include <iostream>
#include <iomanip>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  float a = 0.0;
  while (1) {
    cin >> a;
    if (a==-1.0)break;
    cout << fixed << setprecision(2);
    cout << "Objects weighing " << a << " on Earth will weigh " << a*0.167 << " on the moon.\n";
  }

  return 0;
}