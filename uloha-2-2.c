// uloha-2-2.c -- Tyzden 2 - Uloha 2
// Stanislav Jakubek, 25.2.2016 10:02:35

#include <stdio.h>
#include <stdlib.h>

/*
i - pocitadlo od 0 po T
j - pocitadlo od 0 po N
k - 1 ak vlastni papriku, 0 ak ju nevlastni
akt - cena aktualne kupenej papriky
zisk - zisk
pole - pole do ktoreho sa uklada cena v jednotlivych dnoch
*/
int main() {
  int T, N, i, j, k=0, akt=0, zisk=0;
  
  scanf("%d\n", &T);
  
  for (i = 0; i < T; i++) {
    scanf("%d ", &N);
    int *pole;
    
    pole = (int *) malloc (N * sizeof(int));
    
    for (j = 0; j < N; j++) {
      scanf("%d ", &pole[j]);
    }
    
    for (j = 0; j < N; j++) {
      if ((j == 0) && (pole[1] > pole[0])) {
        k = 1;
        akt = pole[j];
      }
      else if ((k == 0) && (pole[j+1] <= pole[j]));
      else if ((k == 0) && (pole[j+1] > pole[j])) {
        k = 1;
        akt = pole[j];
      }
      else if ((k == 1) && (pole[j+1] > pole[j])) {
        zisk += (pole[j] - akt);
        akt = pole[j];
      }
      else if ((k == 1) && (pole[j+1] <= pole[j])) {
        zisk += (pole[j] - akt);
        k = 0;
      }
    }
    printf("%d\n", zisk);
    free(pole);
    zisk = 0;
    akt = 0;
    k = 0;
  }

  return 0;
}
