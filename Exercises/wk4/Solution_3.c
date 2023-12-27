#include <stdio.h>

int main(void){
	int n;
	printf("What is the array size?\n");
	scanf("%d", &n);
	
	if(n <= 1){
                printf("Array is too small to make pairs\n");
                return 0;
        }

	int arr[n];

	for(int i = 0; i < n; i++){
		printf("Please enter value number %d for the array:\n", i);
		scanf("%d", &arr[i]);
	}

	printf("Your array: ");
	for(int i = 0; i < n; i++){
		printf("%d ", arr[i]);
	}
	printf("\n");

	printf("AND_pairs:\n");
	for(int i = 0; i < n-1; i++){
		for(int j = 1; j < n; j++){
			int no1 = arr[i];
			int no2 = arr[j];
			
			if((no1 & 1) == 1 && (no2 & 1) == 1){
				printf("%d and %d\n", no1, no2);
			}		
		}
	}	
	printf("\n");

	printf("OR_pairs:\n");
	for(int i = 0; i < n-1; i++){
                for(int j = 1; j < n; j++){
                        int no1 = arr[i];
                        int no2 = arr[j];

                        if((no1 & 1) | (no2 & 1) == 1){
                                printf("%d and %d\n", no1, no2);
                        }
                }
        }
	printf("\n");

	printf("XOR_pairs:\n");
	for(int i = 0; i < n-1; i++){
                for(int j = 1; j < n; j++){
                        int no1 = arr[i];
                        int no2 = arr[j];

                        if((no1 & 1) ^ (no2 & 1) == 1){
                                printf("%d and %d\n", no1, no2);
                        }
                }
        }
	printf("\n");
}
