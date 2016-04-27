// uloha-2-1.c -- Tyzden 2 - Uloha 1
// Stanislav Jakubek, 25.2.2016 10:02:23

#include <stdio.h>

/*
N - vstup
max - najvacsi vypocitany pocet 1 a 0
pole[0][N] - pocet nul v cisle N
pole[1][N] - pocet jednotiek v cisle N
*/
int main() {
  int N, pole[2][41], max=1, i;
  
  pole[0][0] = 1;
  pole[1][0] = 0;
  pole[0][1] = 0;
  pole[1][1] = 1;
  
  while (scanf("%d\n", &N) > 0) {
    if (N <= max) {
      //pocet 1 a 0 je uz predpocitany
      printf("%d %d\n", pole[0][N], pole[1][N]);
    }
    else {
      for (i = 2; i <= N; i++) {
        pole[0][i] = (pole[0][i-1] + pole[0][i-2]);
        pole[1][i] = (pole[1][i-1] + pole[1][i-2]);
      }
      printf("%d %d\n", pole[0][N], pole[1][N]);
    }
  }

  return 0;
}
