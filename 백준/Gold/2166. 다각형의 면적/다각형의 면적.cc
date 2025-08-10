#include <stdio.h>

int main() {
  long long n, x[10001], y[10001], sum1=0, sum2=0;
  scanf("%d",&n);
  for (int i = 0; i < n; i++) scanf("%lld %lld",&x[i],&y[i]);
  x[n] = x[0];
  y[n] = y[0];

  for (int i=0; i<n; i++) sum1 += x[i]*y[i+1];
  for (int i=0; i<n; i++) sum2 += x[i+1]*y[i];

  double result = ((double)sum2 - (double)sum1)/2;
  printf("%.1lf",result>0?result:-result);

  return 0;
}