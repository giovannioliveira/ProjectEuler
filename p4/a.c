#include <stdio.h>
#include <string.h>

#define MAX_N 99

int isPalindromous(char str[]);
void intToStr(int n, char *str);

void main(){
	int i,j;
	char a[10];
	intToStr(123321,a);
	if(isPalindromous(a))
		printf("%s\n",a);
	
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
