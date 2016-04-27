// uloha-8-2.cpp -- Tyzden 8 - Uloha 2
// Stanislav Jakubek, 14.4.2016 09:30:47

#include <stdio.h>
#include <algorithm>
#include <list>

using namespace std;

typedef struct vrchol {
  int cislo;
  struct vrchol **deti;
}VRCHOL;

VRCHOL *init(int num) {
  int i;
  VRCHOL *v = (VRCHOL *) malloc (sizeof(VRCHOL));
  
  v->deti = (VRCHOL **) malloc (num * sizeof(VRCHOL*));
  for (i = 0; i < num; i++) {
    v->deti[i] = (VRCHOL *) malloc (sizeof(VRCHOL));
  }
  v->cislo = 0;
  
  return v;
}

int rekurzia(VRCHOL *v) {
  int i=0, result=0;
  
  if (v->cislo == 0) {
    return 1;
  }
  
  std::list<int> zoznam;
  std::list<int>::iterator it;
  
  for (i = 0; i < v->cislo; i++) {
    zoznam.push_back(rekurzia(v->deti[i]));
  }
  
  zoznam.sort();
  zoznam.reverse();
  
  for (i = 0, it = zoznam.begin(); it != zoznam.end(); it++, i++) {
    if (result < (*it + i)) result = *it + i;
  }
  
  return (result + 1);
}

int main(){
  int i, N, num;
  VRCHOL **vrcholy;
  
  while (scanf("%d ", &N) > 0) {
    //alokovanie, inicializacia
    vrcholy = (VRCHOL **) malloc (N * sizeof(VRCHOL*));
    for (i = 0; i < N; i++) {
      vrcholy[i] = init(N);
    }
    //nacitanie udajov
    for (i = 0; i < N; i++) {
      scanf("%d ", &num);
      if (num >= 0) {
        vrcholy[num]->deti[vrcholy[num]->cislo++] = vrcholy[i];
      }
    }
    
    printf("%d\n", rekurzia(vrcholy[0]) - 1);
  }
  
  return 0;
}