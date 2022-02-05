#include <stdio.h>
#include <stdlib.h>

void fib(long int n);

int main(int argc, char* argv[]) {
  char* numsAsString = argv[1];
  long int number = atoi(numsAsString);
  if(number < 0){
    printf("Enter a valid number as argument\n");
    return 0; 
  }
  fib(number);
  return 0;
}

void fib(long int n){
  long int fibs[n+1];
  fibs[0] = 0; 
  fibs[1] = 1; 
  
  if(n==0) printf("%d\n",0);
  if(n==1) printf("%d\n%d\n", 0, 1);

  for(int i = 2; i <= n; i++){
    fibs[i] = fibs[i-1] + fibs[i-2];
    printf("%ld\n", fibs[i]);
  }
}