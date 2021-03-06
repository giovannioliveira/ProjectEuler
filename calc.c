#include "calc.h"

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

int isPrime(bign n){
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
	srand(time(NULL));
	bign randBign;
	for(i=0;i<RABIN_PRECISION;i++){
		//produces rand numbers between 2 and n-2
		randBign = (rand()%(n-4)) + 2;
		x=powmod(randBign,q,n);
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

int integer(bign_d n){
	return !fmod(n,1);
}

int odd(bign n){
	return n&1;
}

int even(bign n){
	return !odd(n);
}

void intToStr(int n, char *str){
	sprintf(str,"%d",n);
}

int isPalindromous(char str[]){
	int len = strlen(str);
	if(len==0||len==1){
		return 1;
	}
	if(str[0]==str[len-1]){
		if(len==2){
			return 1;
		}
		char str2[len-2];
		return isPalindromous(strncpy(str2,&str[1],len-2));
	}else{
		return 0;
	}
}

bign getPalindromous(char str[]){
	int i, size = 2*strlen(str);
	char str2[size+1];
	str2[size] = '\0';
	for(i=0; i<size/2; i++){
		str2[i] = str[i];
	}
	for(i=0; i<size/2; i++){
		str2[size/2 + i] = str[size/2 - i - 1];
	}
	int result;
	sscanf(str2,"%d",&result);
	return result;
}

subgroup relativelyPrimes(int a, int b){
	int i,j,add;
	subgroup result;
	result.n = NULL;
	result.size = 0;
	for(i=b;i>=a;i--){
		add = TRUE;
		for(j=0;j<result.size;j++){
			if(!(result.n[j]%i)){
				add = FALSE;
				break;
			}
		}
		if(add){
			result.size++;
			result.n = realloc(result.n,sizeof(int)*result.size);
			result.n[result.size-1] = i;
		}
	}
	return result;
}

bign subgroupFactorial(subgroup s){
	bign result = 1;
	int i;
	for (i=0;i<s.size;i++){
		result *= s.n[i];
	}
	return result;
}

int subgroupDivides(subgroup s, int n){
	int i;
	for(i=0;i<s.size;i++){
		if(n%s.n[i]){
			return FALSE;
		}
	}
	return TRUE;
}

bign factorial(int n){
	if(n==2){
		return 2;
	}
	return n*factorial(n-1);
}

int chartoi(char c){
	return (c-'0');
}
