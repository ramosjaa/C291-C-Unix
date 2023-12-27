/*
	Jack Ramos
	C291 Assignment 1: #1
	Date: 5/16/2022
*/

#include <stdio.h>

int main(void){
	int physGrade;
	int chemGrade;
	int bioGrade;
	int mathGrade;
	int csGrade;

	int NUM_CLASSES = 5; //constant representing the total number of classes

	printf("Grade Calculator\nPlease enter all grades as an integer 0-100.\n");
	
	printf("What is your Physics grade?\n");
	scanf("%d", &physGrade);

	printf("What is your Chemistry grade?\n");
        scanf("%d", &chemGrade);

	printf("What is your Biology grade?\n");
        scanf("%d", &bioGrade);

	printf("What is your Math grade?\n");
        scanf("%d", &mathGrade);

	printf("What is your Computer Science grade?\n");
        scanf("%d", &csGrade);

	float avgGrade = (float)(physGrade+chemGrade+bioGrade+mathGrade+csGrade)/ (float)NUM_CLASSES;

	char letterGrade;
	if(avgGrade >= 90){
		 letterGrade = 'A';
	} else if(avgGrade >= 80){
		 letterGrade = 'B';
	} else if(avgGrade >= 70){
		 letterGrade = 'C';
	} else if(avgGrade >= 60){
		 letterGrade = 'D';
	} else if(avgGrade >= 40){
		 letterGrade = 'E';
	} else{ //just else here because grade < 40 is the only way for the code to get to this statement
		 letterGrade = 'F';
	}
	
	printf("Total marks: %f\n", avgGrade);
	printf("Grade:  %c\n",  letterGrade);
	return 0;
}
