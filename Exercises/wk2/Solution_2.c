#include <stdio.h>

int main(void){
	int len = 0;
	int num = 1;
	int arr[1024];

	while(num >= 0){
		printf("Enter a number:\n");
		scanf("%d", &num);
		arr[len] = num;
		len++;
	}

	len--; //exclude the negative number at the end
	int arr1[len];
	for(int i = 0; i < len; i++){
		arr1[i] = arr[i]; //copy only the numbers we need
	}

	printf("Your numbers: ");
	for(int i = 0; i < len; i++){
		printf("%d ", arr1[i]);
	}
	printf("\n");

	int max = -1;
	for(int i = 0; i < len; i++){
		if(arr1[i] > max){
			max = arr1[i];
		}
	}

	int sum = 0;
	for(int i = 0; i < len; i++){
		sum += arr1[i];
	}
	
	float average = (float)sum / (float)len;

	printf("Max: %d\nAverage: %f\n", max, average);
	return 0;
}
