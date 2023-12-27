/*
	Jack Ramos
	C291 Assignment 1: #2b
	Date: 5/16/2022
*/

#include <stdio.h>
#include <string.h>

int main(void){
	char monthName[8];
	int year;
	int leapYear;
	int numDays;

	printf("Days in the Month Calculator\nPlease enter months as the full name with the first letter capitalized.\nPlease enter the year as a four digit integer.\n");

	printf("Please enter the month name:\n");
	scanf("%s", monthName);

	printf("Please enter the year:\n");
	scanf("%d", &year);

	leapYear = year % 4; //leap years are every 4 years

	if(strcmp(monthName, "January")==0||strcmp(monthName, "March")==0||strcmp(monthName, "May")==0||strcmp(monthName, "July")==0||strcmp(monthName, "August")==0||strcmp(monthName, "October")==0||strcmp(monthName, "December")==0){ //if user entered a 31-day month
		numDays = 31;
	} else if(strcmp(monthName, "April")==0||strcmp(monthName, "June")==0||strcmp(monthName, "September")==0||strcmp(monthName, "November")==0){ //if user entered a 30-day month
		numDays = 30;
	} else if(strcmp(monthName, "February")==0){ //if user entered February
		if(leapYear == 0){ //year%4 will be zero if the year is a leap year
			numDays = 29;
		} else{
			numDays = 28;
		}
	} else{
		printf("Invalid input.\n");
		return 0; //terminate program if user enters an invalid input
	}

	printf("Number of Days: %d\n", numDays);
	return 0;
}
