// uloha-3-1.c -- Tyzden 3 - Uloha 1
// Stanislav Jakubek, 3.3.2016 10:00:11

#include <stdio.h>
#include <stdlib.h>

void init(int *arr, int B) {
  int i;
  for (i = 0; i <= B; i++) {
    arr[i] = 0;
  }
}

/*
N - pocet povolenych tahov
A - dolny limit poctu ceruziek
B - horny limit poctu ceruziek
i,j - iterativne pomocne premenne
pocet - pocet moznych vyhier
*tahy - pole tahov
*vyhra - pomocne pole - ci je mozne vyhrat zacinajuc tymto cislom
maxvyhra - maximalna hodnota kde moze vyhrat
*/

//pri 50 a tahani 3 nikto nevyhra
//napr. pri 10 a tahoch 1,2 pozrieme ci 8 a 9 su (aspon 1) prehravajuce
int main() {
  int N, A, B, i, j, pocet, *tahy, *vyhra;
  
  while(scanf("%d\n", &N) > 0) {
    //alokacia pola tahov
    tahy = (int *) malloc (N * sizeof(int));
    pocet = 0;
    
    for (i = 0; i < N; i++) {
      //nacitanie hodnot do pola tahov
      scanf("%d ", &tahy[i]);
    }
    
    //nacitanie cisiel A a B
    scanf("%d %d", &A, &B);
    
    //alokacia pola - ci je mozne vyhrat zacinajuc tymto cislom
    vyhra = (int *) malloc ((B + 1) * sizeof(int));
    init(vyhra, B);
    i = 0;
    
    //zistenie ci sa z daneho cisla da vyhrat
    while ((i + tahy[0]) <= B) {
      for (j = 0; j < N; j++) {
        if ((vyhra[i] == 0) && ((i + tahy[j]) <= B)) {
          vyhra[i + tahy[j]] = 1;
        }
      }
      i++;
    }
    
    //spocitanie moznych vyhier v intervale <A,B>
    for (j = A; j <= B; j++) {
      if (vyhra[j] == 1) pocet++;
    }
    
    free(vyhra);
    free(tahy);
    printf("%d\n", pocet);
  }
  
  return 0;
}
