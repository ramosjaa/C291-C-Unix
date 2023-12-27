#include <stdio.h>

float drivingCost(float milesPerGallon, float dollarsPerGallon, float milesDriven);

int main(void){
	float mpg, dpg, miles;
	printf("Enter the miles per gallon:\n");
	scanf("%f", &mpg);

	printf("Enter the dollars per gallon:\n");
	scanf("%f", &dpg);

	printf("Enter the miles driven:\n");
	scanf("%f", &miles);

	printf("%f\n", drivingCost(mpg, dpg, miles));
}

float drivingCost(float milesPerGallon, float dollarsPerGallon, float milesDriven){
	return (milesDriven/milesPerGallon) * dollarsPerGallon;
}
