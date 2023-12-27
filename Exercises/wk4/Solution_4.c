#include <stdio.h>

int main(void){
	int n = 0;

	printf("Enter the size of the array: ");
	scanf("%d", &n);

	int arr[n];
	for(int i = 0; i < n; i++){
		printf("Enter element %d of the array:\n", i);
		scanf("%d", &arr[i]);
	}

	printf("Your array: ");
	for(int i = 0; i < n; i++){
		printf("%d ", arr[i]);
	} printf("\n");

	int output = -1;
	for(int i = 0; i < n-1; i++){
		for(int j = 1; j < n; j++){
			int no1 = arr[i];
			int no2 = arr[j];

			if((no1 ^ no2) == 0){ //will only return true if no1 == no2
				output = no1; //arbitrarily choose no1 since they are equal
				printf("Output: %d\n", output);
				return 0;
			}
		}
	}
}
