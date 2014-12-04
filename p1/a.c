#include <stdio.h>
#define LIMIT 1000
void main(){
	int sum = 0, i;
	for(i=3;i<LIMIT;i++){
		if(!(i%3)||!(i%5))
			sum += i;
	}
	printf("sum is: %d\n",sum);
	return;
}	
