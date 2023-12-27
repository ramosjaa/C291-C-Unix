#include <stdio.h>

int main(void){
	int arrSize;

	printf("Please enter the size of the array:\n");
	scanf("%d", &arrSize);

	int array[arrSize];

	int counter = 0;
	while(counter < arrSize){
		printf("Please enter array value %d\n", counter);
		scanf("%d", &array[counter]); 
		counter++;
	}
	
	int numUnique = 0;
	for(int i = 0; i < arrSize; i++){ //for loop used to count unique values
                if(i == arrSize-1){
			numUnique++;
		} else{
			if(array[i] != array[i+1]){
                                numUnique++;
                	}
		}
        }

	int newArray[numUnique];
	int newCount = 0;
	for(int i = 0; i < arrSize; i++){
		if(i == arrSize-1){
			newArray[newCount] = array[i]; //last element is either a new number or a duplicate of a number that hasn't been added yet
			newCount++;
		} else{ //to make sure everything stays in bounds
			if(array[i] != array[i+1]){
				newArray[newCount] = array[i]; //add every number change
				newCount++;
			}
		}
	}

	for(int i = 0; i < numUnique; i++){
		printf("%d ", newArray[i]);
	} printf("\n");
}
