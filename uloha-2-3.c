// uloha-2-3.c -- Tyzden 2 - Uloha 3
// Stanislav Jakubek, 25.2.2016 10:03:04

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void init(int *arr) {
  int i;
  for (i = 0; i < 51; i++) {
    arr[i] = 0;
  }
}

/*
arr[51] - pole s nacitanymi cislami
help - pomocna premenna, ak < 0 tak program vrati 0
check - pomocna premenna, 0 ak su dvojice (00 11 22...) 1 ak osamote (3 4 5...)
i - iterativna pomocna premenna
maxNumber - pomocna premenna
*/
int main() {
  int offset, n, arr[51], help=0, check=0, i, maxNumber;
  char *line = (char *) malloc (1000);
  
  while (fgets(line, 1000, stdin) > 0) {
    init(arr);
    maxNumber = -1;
    
    while(sscanf(line, "%d%n", &n, &offset) == 1) {
      line += offset;
      arr[n]++;
      if (maxNumber < 0 || maxNumber < n) maxNumber = n;
      if ((n > 50) || (arr[n] > 2)) {
        help = -1;
        break;
      }
    }
    
    check = 0;
    
    for (i = 0; (i < 51) && (help >= 0); i++) {
      if ((i + 1 < 51 && arr[i] < arr[i + 1]) ||
          (arr[i + 1] - arr[i] > 1)) {
        help = -1;
        break;
      }
      
      if (arr[i] > 2) {
        help = -1;
        break;
      }
      
      if (check && arr[i] > 1) {
        help = -1;
        break;
      }
      
      if (arr[i] == 2) { help++; }
      
      if (arr[i] == 1) {
        if (!check) help++;
        check = 1;
      }
      
      if (arr[i] == 0) { break; }
    }
    
    if(maxNumber > i){
		help = -1;
	}
    
    if (help > 0) printf("%d\n", (int) pow (2, help));
    if (help < 0) printf("0\n");
    help = 0;
  }

  return 0;
}
