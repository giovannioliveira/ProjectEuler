#include <stdio.h>
#include <math.h>
#include <string.h>

typedef unsigned long long int bign;
typedef long double bign_d;

typedef struct{
	bign a;
	bign b;
} factors;


//functions used in 3rd problem
//uses fermat
factors getFactors(bign n);
//uses miller-rabin with precision with 4p
bign prime(bign n);
//reduces exp product to mod
bign powmod(bign a, bign b, bign mod);
int integer(bign_d n);
int odd(bign n);
int even(bign n);

//functions used in 4th problem
int isPalindromous(char str[]);
void intToStr(int n, char *str);
