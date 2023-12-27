#include <stdio.h>
#define NUM_ITEMS 3

struct Address{
	char * street;
	char * city;
	char * state;
	char * zip;
};

struct Product{
	char * name;
	double price;
};

struct Item{
	struct Product prod;
	int quantity;
};

struct Invoice{
	struct Item * items;
	struct Address address;
};

struct Address createAddress(char * street, char * city, char * state, char * zip);
struct Product createProducts(char * name, double price);
struct Item createLineItem(struct Product prod, int quantity);
struct Invoice createInvoice(struct Item * items, struct Address address);
void printInvoice(struct Invoice invoice);

int main(void){
	struct Address address = createAddress("Street Name", "City Name", "State", "Zip"); //edit these values
	struct Product prod1 = createProducts("Product 1", 3.99);
	struct Product prod2 = createProducts("Product 2", 8.99);
	struct Product prod3 = createProducts("Product 3", 0.99);

	struct Item items[NUM_ITEMS] = {createLineItem(prod1, 2), createLineItem(prod2, 4), createLineItem(prod3, 7)};

	struct Invoice invoice = createInvoice(items, address);
	printInvoice(invoice);
}

struct Address createAddress(char * street, char * city, char * state, char * zip){
	struct Address address;
	address.street = street;
	address.city = city;
	address.state = state;
	address.zip = zip;

	return address;
}

struct Product createProducts(char * name, double price){
	struct Product product;
	product.name = name;
	product.price = price;

	return product;
}

struct Item createLineItem(struct Product prod, int quantity){
	struct Item item;
	item.prod = prod;
	item.quantity = quantity;

	return item;
}

struct Invoice createInvoice(struct Item * items, struct Address address){
	struct Invoice invoice;
	invoice.items = items;
	invoice.address = address;

	return invoice;
}

void printInvoice(struct Invoice invoice){
	//retrieve all information first (for clarity's sake)
	struct Item * items = invoice.items;
	struct Address address = invoice.address;

	printf("------I N V O I C E------\n");
	printf("Sam's Small Appliances\n");
	printf("%s\n", address.street);
	printf("%s, %s %s\n\n", address.city, address.state, address.zip);
	printf("Description    Price   Qty   Total\n");

	double amountDue = 0.0;

	
	 for(int i = 0; i < NUM_ITEMS; i++){
	 	printf("%s   %f  %d  %f\n", items[i].prod.name, items[i].prod.price, items[i].quantity, items[i].prod.price * items[i].quantity);
	 	amountDue += items[i].prod.price * items[i].quantity;
	 }
	 printf("AMOUNT DUE: %f\n", amountDue);
}
