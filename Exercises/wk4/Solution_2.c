#include <stdio.h>
#define NUM_TRANSACTIONS 10
#define SALES_TAX 0.07

struct SelfCheckOut{
        int customersServed;
        double totalSales;
        double currAmountDue;
};


int getCustomersServed(struct SelfCheckOut s);
double getTotalSales(struct SelfCheckOut s);
double currentAmountDue(struct SelfCheckOut s);
void initializeSelfCheckOut(struct SelfCheckOut s);
struct SelfCheckOut scanItem(struct SelfCheckOut s, double price);
struct SelfCheckOut checkOut(struct SelfCheckOut s);
struct SelfCheckOut makePayment(struct SelfCheckOut s, double payment);
struct SelfCheckOut simulateSales(struct SelfCheckOut s, int numSales);

int main(void){
	struct SelfCheckOut s;
	initializeSelfCheckOut(s);

	//to test the first three methods (all should be zero)
	printf("Customers Served: %d\n", getCustomersServed(s));
	printf("Total Sales: %f\n", getTotalSales(s));
	printf("Current Amount Due: %f\n", currentAmountDue(s));

	simulateSales(s, NUM_TRANSACTIONS);
}

int getCustomersServed(struct SelfCheckOut s){
	return s.customersServed;
}

double getTotalSales(struct SelfCheckOut s){
	return s.totalSales;
}

double currentAmountDue(struct SelfCheckOut s){
	return s.currAmountDue;
}

void initializeSelfCheckOut(struct SelfCheckOut s){
	s.customersServed = 0;
	s.totalSales = 0;
	s.currAmountDue = 0;
}

struct SelfCheckOut scanItem(struct SelfCheckOut s, double price){
	s.currAmountDue += price;
	return s;
}

struct SelfCheckOut checkOut(struct SelfCheckOut s){
	s.currAmountDue += s.currAmountDue*SALES_TAX;
	printf("Current amount due: $%f\n", s.currAmountDue);
	return s;
}

struct SelfCheckOut makePayment(struct SelfCheckOut s, double payment){
	if(payment == s.currAmountDue){
		s.totalSales += payment;
		s.currAmountDue = 0;
		printf("Thank you! Have a nice day.\n");
	} else{
		s.totalSales += payment;
		s.currAmountDue -= payment;	
		printf("You still owe $%f\n", s.currAmountDue);
	}
	return s;
}

struct SelfCheckOut simulateSales(struct SelfCheckOut s, int numSales){
	for(int i = 0; i < numSales; i++){
		double price = 7.4; //random double between 1 and 10
		s = scanItem(s, price);
		printf("Scanned item that costs $%f\n", price);
	}
	double payment = 8.0; //random double between 5 and 11
	s = checkOut(s);
	while(s.currAmountDue > 0){ //not sure if I need to keep trying the payment until the amount is paid but I'm implementing it just in case
		s = makePayment(s, payment); //if this is unnecessary we would just not have this line in a while loop
	}
	return s;
}
