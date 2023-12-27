/*
	Jack Ramos
	C291 Assignment 1: #4
	Date: 5/16/2022
*/

#include <stdio.h>

int main(void){
	int integer1;
	int integer2;
	char operator;
	float result; //making result a float to handle division

	printf("Please enter the first integer (0-10^6)\n");
	scanf("%d", &integer1);

	printf("Please enter the second integer (0-10^6)\n");
	scanf("%d", &integer2);

	printf("Please enter the desired operator (+ - * /)\n");
	scanf(" %c", &operator);

	if(operator == '+'){
		result = integer1 + integer2;
		printf("%d %c %d = %d\n", integer1, operator, integer2, (int)result); //cast result as an int if not integer division
	} else if(operator == '-'){
		result = integer1 - integer2;	
		printf("%d %c %d = %d\n", integer1, operator, integer2, (int)result);
	} else if(operator == '*'){
		result = integer1 * integer2;
		printf("%d %c %d = %d\n", integer1, operator, integer2, (int)result);
	} else if(operator == '/'){
		result = (float)integer1/ (float)integer2;
		if(result > integer1/integer2){ //if division results in a decimal (integer1/integer2 will truncate and be smaller than result if so)
			printf("%d %c %d = %f\n", integer1, operator, integer2, result);
		} else{
			printf("%d %c %d = %d\n", integer1, operator, integer2, (int)result);
		}
	} else{
		printf("Invalid operator.\n");
		return 0; //terminate program if invalid operator is entered
	}
}
