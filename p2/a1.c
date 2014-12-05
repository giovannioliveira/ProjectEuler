#include <stdio.h>

#define LIMIT 4000000

//sums all even of fibonacci sequence until term get bigger than LIMIT
void main(){
	int a=1, b=2, aux, sum = 0;
	while((a+b)<=LIMIT){
		aux = b;
		b += a;
		a = aux;
		if(!(a%2))
			sum += a;
	}
	if(!(b%2))
		sum += b;
	printf("s(n) = %d\n",sum);
	return;
}
