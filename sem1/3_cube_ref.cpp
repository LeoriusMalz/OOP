#include <iostream>
using std::cin, std::cout, std::endl;

void cubeR(int& r) {
	r = r * r;
}

int main() {
	int a = 0;

	cin >> a;
	cubeR(a);
	cout << a << endl;
}