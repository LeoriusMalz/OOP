#include <iostream>
using std::cout, std::cin, std::endl;

struct Book {
	char title[100];
	int pages;
	float price;
};

void addPrice(Book& b, float x) {
	b.price += x;
}

int main() {
	Book b = {"Прежде чем я упаду", 496, 1084.32};
	float addition = 0;

	cin >> addition;
	cout << b.title << " " << b.pages << " " << b.price << endl;
	addPrice(b, addition);
	cout << b.title << " " << b.pages << " " << b.price << endl;
}