// uloha-7-1.c -- Tyzden 7 - Uloha 1

#include <stdio.h>

double NnadK(double N, int K) {
  int i;
  double result=1;
  
  for (i = N; i > N-K; i--) {
    result *= i;
  }
  
  for (i = 1; i <= K; i++) {
    result /= i;
  }
  
  //printf("%lf nad %d = %lf\n", N, K, result);
  return result;
}

double NnaK(double N, int K) {
  int i;
  double result=1;
  
  for (i = 0; i < K; i++)
    result *= N;
  
  //printf("%lf na %d = %lf\n", N, K, result);
  return result;
}

//Bernoulio schema
int main() {
  int i, j=0, PC[7] = {2,3,5,7,11,13,17};
  double A, B, PA=0, PB=0, temp;
  
  while (scanf("%lf %lf\n", &A, &B) > 0) {
    //printf("%lf %lf\n", A, B);
    
    A = A/100;
    B = B/100;
    
    for (i = 0; i < 18; i++) {
      if (i == PC[j]) {
        temp = NnadK(18, PC[j]) * NnaK(A, PC[j]) * NnaK(1-A, 18-PC[j]);
        PA += temp;
        //printf("%lf %lf\n", PA, temp);
        
        temp = NnadK(18, PC[j]) * NnaK(B, PC[j]) * NnaK(1-B, 18-PC[j]);
        PB += temp;
        //printf("%lf %lf\n", PB, temp);
        
        j++;
      }
    }
    j = 0;
    printf("%.9lf\n", 1 - (1 - PA)*(1 - PB));
  }
  
  return 0;
}
