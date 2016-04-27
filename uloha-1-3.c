// uloha-1-3.c -- Tyzden 1 - Uloha 3
// Stanislav Jakubek, 18.2.2016 10:15:37

#include <stdio.h>

// vypocita x^n
double xn(double x, int n) {
  double v = 1;
  
  while (n > 0) {
    if (n & 1) v *= x;
    n >>= 1;
    x *= x;
  }
  
  
  return v;
}

// ukazkovy test
int main(void)
{
  int i;
  for (i = 0; i < 32; i++)
    printf("2^%d = %lf\n", i, xn(2.0, i));
  return 0;
}
