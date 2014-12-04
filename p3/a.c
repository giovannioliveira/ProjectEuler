#include <stdio.h>
#include <math.h>

#define N 600851475143

typedef unsigned long long int bign;
typedef long double bign_d;

typedef struct{
	bign a;
	bign b;
} factors;

factors getFactors(bign n);
bign bigger(bign n, bign m);
bign odd(bign n);
bign even(bign n);
bign integer(bign_d n);
bign powmod(bign a, bign b, bign mod);
bign prime(bign n);

void main(){
	factors f = getFactors(N);
	while(!prime(f.a)){
		f.a = getFactors(f.a).b;
	}
	while(!prime(f.b)){
		f.b = getFactors(f.b).b;
	}
	printf("%llu\n",bigger(f.a,f.b));
}

bign bigger(bign n, bign m){
	if(n>m){
		return n;	
	}else{
		return m;
	}
}

factors getFactors(bign n){
	factors f;
	if(even(n)){
		f.a = n/2;
		f.a = 2;
		return f;
	}
	if(integer(sqrt(n))){
		f.a = (bign)sqrt(n);
		f.b = f.a;
		return f;
	}
	bign_d x =(bign)sqrt(n), y;
	for(;x<n;x++){
		y = sqrt(pow(x,2)-n);
		if(integer(y)){
			f.a = (bign)(x-y);
			f.b = (bign)(x+y);
			return f;
		}
	}
	f.a = n;
	f.b = 1;
	return f;
}

bign prime(bign n){
	bign i, j, k=0, q=n-1, x;
	if(n<=1){
		return 0;
	}else if(n==2){
		return 1;
	}else if(even(n)){
		return 0;
	}
	while(integer(q/2.0)){
		q/=2;
		k++;
	}
	for(i=2;i<5;i++){
		x=powmod(i,q,n);
		if(x==1||x==(n-1)){
			continue;
		}else{
			for(j=0;j<(k-1);j++){
				x = powmod(x,2,n);
				if(x==1){
					return 0;
				}else if(x==(n-1)){
					j=k;
					break;
				}
			}
			if(j==(k-1)){
				return 0;
			}
		}
	}
	return 1;
}

bign powmod(bign a, bign b, bign mod){
	bign i, result;
	if(!b){
		return 1;
	}
	result = a%mod;
	for(i=0;i<b-1;i++){
		result = ((result*a)%mod);
	}
	return result;
}

bign integer(bign_d n){
	return !fmod(n,1);
}

bign odd(bign n){
	return n&1;
}

bign even(bign n){
	return !odd(n);
}
