// uloha-7-2.c -- Tyzden 7 - Uloha 2
// Stanislav Jakubek, 7.4.2016 10:09:40

#include <stdio.h>

int main() {
  int i, j, N, RGB[2][3], temp;
  
  while (scanf("%d\n", &N) > 0) {
    //inicializacia pola
    for (i = 0; i < 2; i++)
      for (j = 0; j < 3; j++)
        RGB[i][j] = 0;
    
    //prvotne nacitanie
    scanf("%d %d %d\n", &RGB[0][0], &RGB[0][1], &RGB[0][2]);
    
    //(N-1)-krat cyklus
    for (i = 1; i < N; i++) {
      scanf("%d ", &temp);
      if (RGB[0][1] < RGB[0][2]) RGB[1][0] = temp + RGB[0][1];
      else RGB[1][0] = temp + RGB[0][2];
      
      scanf("%d ", &temp);
      if (RGB[0][0] < RGB[0][2]) RGB[1][1] = temp + RGB[0][0];
      else RGB[1][1] = temp + RGB[0][2];
      
      scanf("%d\n", &temp);
      if (RGB[0][0] < RGB[0][1]) RGB[1][2] = temp + RGB[0][0];
      else RGB[1][2] = temp + RGB[0][1];
      
      RGB[0][0] = RGB[1][0];
      RGB[0][1] = RGB[1][1];
      RGB[0][2] = RGB[1][2];
    }
    
    temp = RGB[0][0];
    if (RGB[0][1] < temp) temp = RGB[0][1];
    if (RGB[0][2] < temp) temp = RGB[0][2];
    
    printf("%d\n", temp);
  }
  
  return 0;
}
