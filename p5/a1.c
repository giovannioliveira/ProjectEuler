#include "../calc.h"

#define RANGE_MAX 20

void main(){
	subgroup s = relativelyPrimes(2, RANGE_MAX);
	bign maxn = subgroupFactorial(s);
	bign i;
	for(i=RANGE_MAX; i<maxn; i+=RANGE_MAX){
		if(subgroupDivides(s,i)){
			printf("n = %llu\n", i);
			return;
		}
	}
	printf("n = %llu\n", maxn);
}
