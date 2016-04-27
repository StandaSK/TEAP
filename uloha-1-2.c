// uloha-1-2.c -- Tyzden 1 - Uloha 2
// Stanislav Jakubek, 18.2.2016 10:15:17

#include <stdio.h>
#include <stdlib.h>

int cmpfunc (const void * a, const void * b) {
  //source: http://www.tutorialspoint.com/c_standard_library/c_function_qsort.htm
   return ( *(int*)a - *(int*)b );
}

// maximalne 2 do kamionu
int main() {
  int N, i, j=0, k, akt;
  
  while (scanf("%d ", &N) > 0) {
    
    int pole[N], pocet=0;
  
    for (i = 0; i < N; i++) {
      scanf("%d ", &akt);
      if (akt > 199) { /*printf("TEST>200\n");*/ pocet++; }
      else {
        pole[j] = akt;
        j++;
      }
    }
    
    qsort(pole, j, sizeof(int), cmpfunc);
    
    //zoberie najvacsi prvok v poli a snazi sa k nemu priradit co najvacsi iny prvok
    for (k = j-1; k >= 0; k--) {
      if (pole[k] != 0) {
        if (k == 0) { /*printf("TEST posledny\n");*/ pocet++; }
        for (i = k-1; i >= 0; i--) {
          if ((pole[i] != 0) && (pole[k] + pole[i] <= 300)) {
            //printf("TEST pole[i] %d pole[k] %d\n", pole[i], pole[k]);
            pole[k] = 0;
            pole[i] = 0;
            pocet++;
            i = -1;
          }
          else if (i == 0) { /*printf("TEST moc velky\n");*/ pocet++; }
        }
      }
    }
    j = 0;
    printf("%d\n", pocet);
  }
  
  return 0;
}
