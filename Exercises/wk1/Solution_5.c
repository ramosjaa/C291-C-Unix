/*
	Jack Ramos
	C291 Assignment 1: #5
	Date: 5/16/2022
*/

#include <stdio.h>

int main(void){
	char morning;
	char mom;
	char sleeping;


	printf("Is it morning? [y]es [n]o\n");
	scanf(" %c", &morning);

	printf("Is it mom calling? [y]es [n]o\n");
	scanf(" %c", &mom);

	printf("Am I sleeping? [y]es [n]o\n");
	scanf(" %c", &sleeping);

	if(sleeping == 'y'){ //don't answer if sleeping regardless of everything else
		printf("Don't answer.\n");
	} else{
		if(morning == 'y'){ //morning result depends on mom
			if(mom == 'y'){
				printf("Answer.\n");
			} else{
				printf("Don't answer.\n");
			}
		} else{ //answer if it's not morning and not sleeping
			printf("Answer.\n");
		}
	}
}
