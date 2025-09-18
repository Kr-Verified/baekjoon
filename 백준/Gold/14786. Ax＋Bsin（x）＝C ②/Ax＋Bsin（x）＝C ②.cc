#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

double a, b, c;

double f(double x) {
  return a*x + b*sin(x) - c;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> a >> b >> c;
  double low = (c - fabs(b)) / a;
  double high = (c + fabs(b)) / a;
  if (low > high) swap(low, high);

  double mid;
  for (int i = 0; i < 100; i++) {
    mid = low + (high - low) / 2;
    if (f(mid) == 0) break;
    if (f(low) * f(mid) <= 0) high = mid;
    else low = mid;
  }

  cout << setprecision(20) << mid << '\n';

  return 0;
}