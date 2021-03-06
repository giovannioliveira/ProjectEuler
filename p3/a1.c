#include "../calc.h"

#define N 600851475143

//get bigger prime factor of number N
void main(){
	factors f = getFactors(N);
	while(!isPrime(f.a)){
		f.a = getFactors(f.a).b;
	}
	while(!isPrime(f.b)){
		f.b = getFactors(f.b).b;
	}
	printf("bigger factor: %llu\n",(f.a>f.b)?f.a:f.b);
}
