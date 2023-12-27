#include <stdio.h>
#include <math.h>

//prototypes
float binomialDistribution(int k, int n, float p);
int factorial(int n);
float power(float x, float y);

int main(void){
	int k, n;
	float p;

	printf("Enter the k value:\n");
	scanf("%d", &k);

	printf("Enter the n value:\n");
	scanf("%d", &n);

	printf("Enter the p value:\n");
	scanf("%f", &p);

	printf("The probability is %f\n", binomialDistribution(k, n, p));
}

float binomialDistribution(int k, int n, float p){	
	float c;
	float answer = 0;

	c = (float)(factorial(n)) / (float)(factorial(k) * factorial(n-k)); //compute c value
	answer = c * power(p, k) * power((1-p), (n-k)); //compute the rest of the formula
	return answer;
}

int factorial(int n){
	if(n <= 1){
		return 1;
	}
	return n * factorial(n-1);
}

float power(float x, float y){
	if(y == 0){
		return 1;
	}
	
	float result = 1;
	for(int i = 0; i < y; i++){
		result *= x;
	}
	return result;
}
