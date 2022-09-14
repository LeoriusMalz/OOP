#include <iostream>
using std::cout, std::endl;

struct Book {
	char title[100];
	int pages;
	float price;
};

bool isExpensive(const Book& b) {
	if (b.price > 1000)
		return true;
	else
		return false;
}

int main() {
	Book b = {"Прежде чем я упаду", 496, 984.32};

	cout << b.title << " " << b.pages << " " << b.price << endl;
	cout << isExpensive(b);
}