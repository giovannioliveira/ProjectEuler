#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define TRUE 1
#define FALSE 0

#define RABIN_PRECISION 10

typedef unsigned long long int bign;
typedef long double bign_d;

typedef struct{
	bign a;
	bign b;
} factors;

typedef struct{
	int *n;
	int size;
} subgroup;


//functions used in 3rd, 4th and 7th problems
//uses fermat
factors getFactors(bign n);
//uses miller-rabin with precision with 4p
int isPrime(bign n);
//reduces exp product to mod
bign powmod(bign a, bign b, bign mod);
int integer(bign_d n);
int odd(bign n);
int even(bign n);

//functions used in 4th problem
int isPalindromous(char str[]);
void intToStr(int n, char *str);
//returns bigger palidromous integer based in the first n numbers ex.: 123 -> 123321
int getPalindromous(char str[]);

//functions used in 5th problem
subgroup relativelyPrimes(int a, int b);
bign subgroupFactorial(subgroup s);
int subgroupDivides(subgroup s, int n);
bign factorial(int n);


