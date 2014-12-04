#include <stdio.h>
#include <math.h>

#define N 2

typedef struct{
	int a;
	int b;
} factors;

typedef unsigned long long int bign;

factors getFactors(int n);
int bigger(int n, int m);
int odd(int n);
int even(int n);
int integer(double n);
int powmod(int a, int b, int mod);

void main(){
	printf("%d\n",prime(2729));
}

int bigger(int n, int m){
	if(n>m){
		return n;	
	}else{
		return m;
	}
}

factors getFactors(int n){
	factors f;
	if(even(n)){
		f.a = n/2;
		f.a = 2;
		return f;
	}
	if(integer(sqrt(n))){
		f.a = (int)sqrt(n);
		f.b = f.a;
		return f;
	}
	double x =(int)sqrt(n), y;
	for(;x<n;x++){
		printf("x:%d\n",(int)x);
		y = sqrt(pow(x,2)-n);
		printf("%f\n",y);
		if(integer(y)){
			f.a = (int)(x-y);
			f.b = (int)(x+y);
			return f;
		}
	}
	f.a = n;
	f.b = 1;
	return f;
}

int prime(int n){
	int i, j, k=0, q=n-1, x;
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
	for(i=2;i<(n-1);i++){
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

int powmod(int a, int b, int mod){
	int i, result;
	if(!b){
		return 1;
	}
	result = a%mod;
	for(i=0;i<b-1;i++){
		result = ((result*a)%mod);
	}
	return result;
}

int integer(double n){
	return !fmod(n,1);
}

int odd(int n){
	return n&1;
}

int even(int n){
	return !odd(n);
}
