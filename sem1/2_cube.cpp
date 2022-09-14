#include <iostream>
using std::cin, std::cout, std::endl;

int cubeV(int r) {
	return r * r;
}

int main() {
	int a = 0;

	cin >> a;
	cout << cubeV(a) << endl;
}