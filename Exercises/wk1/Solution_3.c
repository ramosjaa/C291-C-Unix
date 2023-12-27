/*
	Jack Ramos
	C291 Assignment 1: #3
	Date: 5/16/2022
*/

#include <stdio.h>

int main(void){
	int ang1;
	int ang2;
	int ang3;

	printf("Triangle Type and Validity\nPlease enter angles as positive integers representing degrees.\n");

	printf("Value of angle 1:\n");
	scanf("%d", &ang1);

	printf("Value of angle 2:\n");
        scanf("%d", &ang2);

	printf("Value of angle 3:\n");
        scanf("%d", &ang3);


	if((ang1 + ang2 + ang3 == 180) && (ang1 > 0) && (ang2 > 0) && (ang3 > 0)){ //angles must add up to 180 and all must be greater than 0
		printf("The triangle is valid.\n");
		if((ang1 < 90) && (ang2 < 90) && (ang3 < 90)){ //acute triangle if angles are all less than 90 degrees
			printf("It is an acute triangle.\n");
		} else if((ang1 == 90) || (ang2 == 90) || (ang3 == 90)){ //right triangle if one of the angles is equal to 90 degrees 
			printf("It is a right triangle.\n");
		} else if((ang1 > 90) || (ang2 > 90) || (ang3 > 90)){ //obtuse triangle if one of the angles is greater than 90 degrees
			printf("It is an obtuse triangle.\n");
		}
	} else{ 
		printf("The triangle is invalid.\n");
			
	}
}
