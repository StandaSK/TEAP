// uloha-1-1.c -- Tyzden 1 - Uloha 1
// Stanislav Jakubek, 18.2.2016 10:08:38

#include <stdio.h>
#include <stdlib.h>

int cmpfunc (const void *a, const void *b) {
  //source: http://www.tutorialspoint.com/c_standard_library/c_function_qsort.htm
   return ( *(int*)a - *(int*)b );
}

int main() {
  int N, K, M, i;
  
  while (scanf("%d %d %d ", &N, &K, &M) > 0) {
    int pole[M], sucet=0;
    
    for (i = 0; i < M; i++) {
      scanf("%d ", &pole[i]);
    }
    
    qsort(pole, M, sizeof(int), cmpfunc);
    
    for (i = M-1; i >= (M-K); i--) {
      sucet += pole[i];
    }
    
    if (sucet > N) printf("Nie\n");
    else printf("Ano\n");
  }
  
  return 0;
}
