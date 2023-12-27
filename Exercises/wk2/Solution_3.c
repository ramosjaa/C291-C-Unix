#include <stdio.h>

int main(void){
	int primes[10] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29};
	int num;

	printf("Enter an integer:\n");
	scanf("%d", &num);

	int factors[1024];	
	int factCount = 0;
	while(num > 1){
		for(int i = 0; i < 10; i++){
			if((num % primes[i]) == 0){ //if num is divisible by one of the prime numbers
				num /= primes[i]; 
				factors[factCount] = primes[i]; //add prime number to the array
				factCount++;
				continue;
			}
			if(num == primes[i]){
				break;
			}
		}
	}

	printf("Factors: ");
	for(int i = 0; i < factCount; i++){
		printf("%d ", factors[i]);
	}
	printf("\n");
}
