#include <stdio.h>

int main(void){
	int integer, integerCpy;
	
	printf("Enter a positive integer:\n");
	scanf("%d", &integer);
	
	integerCpy = integer;

	int length = 0;
	while(integerCpy > 0){
		integerCpy /= 2;
		length++;
	}

	char str[length], reverseStr[length];
	integerCpy = integer;
	for(int i = 0; i < length; i++){
		//printf("%d\n", i);
		str[i] = integerCpy % 2; 
		integerCpy /= 2;
	}

	/*
	int counter1 = 215;
	for(int i = 0; i < length; i++){
		reverseStr[counter1] = str[i]; //save reverse of str in reverseStr
		counter1--;
	}
	*/
	printf("Reverse binary of %d is ", integer);
	for(int i = 0; i < length; i++){
		printf("%d", str[i]);
	}	
	printf("\n");
}
