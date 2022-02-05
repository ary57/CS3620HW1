#include <stdio.h>
#include <stdlib.h>

void primes(int n);
int isPrime(int i);

int main(int argc, char* argv[]) {
  char* numsAsString = argv[1];
  int number = atoi(numsAsString);
  if(number < 0){
    printf("Enter a valid number as argument\n");
    return 0; 
  }
  primes(number);
  return 0;
}

void primes(int n){
  printf("%d\n", n); 
  for(int i = 1; i < n; i++){
    if(isPrime(i)) printf("%d\n", i); 
  }
}

int isPrime(int i){
  for(int j = 2; j < i; j++)
    if(i%j == 0) return 0; 
  return 1; 
}