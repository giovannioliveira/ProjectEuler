#include "../calc.h"

#define MAX_N 997 //999^2 = 998001
#define MIN_N 100

void main(){
	int i;
	for (i=MAX_N; i>0; i--){
		char str[4];
		intToStr(i,str);
		int n = getPalindromous(str);
		if(!prime(n)){
			factors f = getFactors((bign)n);
			if(f.a<=MAX_N && f.b>=MIN_N &&
					f.b<=MAX_N && f.b>=MIN_N){
				printf("bigger palindromous: %d\n",n);
				return;
			}
		}
	}
}
