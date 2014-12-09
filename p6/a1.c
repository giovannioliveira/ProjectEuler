#include "../calc.h"

#define LIMIT 100

void main(){
	bign sumsqr = 0, sqrsum = 0;
	int i, j;
	for(i=1;i<=LIMIT; i++){
		sumsqr += pow(i,2);
	}
	sqrsum = pow((((LIMIT+1)/2.0)*LIMIT),2);
	bign diff = sqrsum - sumsqr;
	printf("%llu\n",diff);
}
