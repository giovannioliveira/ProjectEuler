#include <stdio.h>

#define LIMIT 1000
#define A 3
#define B 5
#define AB (A*B)

//sums all multiples of 3 and/or 5 until LIMIT
void main(){
	int sum = 0, i, n1, n2, n3;
	n1 = (LIMIT-1)/A;
	n2 = (LIMIT-1)/B;
	n3 = (LIMIT-1)/AB;
	sum += ((A+A*n1)*n1/2);
	sum += ((B+B*n2)*n2/2);
	sum -= ((AB+AB*n3)*n3/2);
	printf("sum: %d\n",sum);
	return;
}
