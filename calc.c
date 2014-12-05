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
