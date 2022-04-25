#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <stdlib.h>

void prime_fac(unsigned long long int n, FILE* F, bool print) {
  unsigned long long int i = 2;
  unsigned long long int lim = (unsigned long long int) sqrt(n);
  if (print) {
    printf("%llu: ", n);
  } else {
    fprintf(F, "%llu: ", n);
  }
  while (i <= lim) {
    if (n % i != 0) {
      i++;
    } else {
      if (print) {
	printf("%llu ", i);
      } else {
	fprintf(F, "%llu ", i);
      }
      n /= i;
    }
  }
  if (n != 1) {
    if (print) {
      printf("%llu", n);
    } else {
      fprintf(F, "%llu", n);
    }
  }
  if (print) {
    printf("\n");
  } else {
    fprintf(F, "\n");
  }
}

int main(int argc, char* argv[]) {
  unsigned long long int i = 2;
  unsigned long long int n;
  char* eptr;
  char* filename;
  FILE* F = NULL;
  if (argc == 3) {
    filename = argv[1];
    n = strtoull(argv[2], &eptr, 10);
    F = fopen(filename, "w");
    if (F) {
      while (i < n) {
	prime_fac(i, F, false);
	i++;
      }
      fclose(F);
    }
  } else if (argc == 2) {
    n = strtoull(argv[1], &eptr, 10);
    prime_fac(n, F, true);
  } else {
    printf("Usage: ./a.out filename number\nOR\n./a.out number\n");
  }
  return 0;
}
