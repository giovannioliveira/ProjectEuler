#include "../calc.h"

#define NTH_PRIME 10001

void main(){
	bign n = 3;
	int primeIndex = 2;
	while(primeIndex!=NTH_PRIME){
		n+=2;
		if(isPrime(n)){
			primeIndex++;
		}
	}
	printf("%dth prime : %llu\n",NTH_PRIME,n);

}
