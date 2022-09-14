#include <iostream>
#include <cstring>
using std::cout, std::endl;

void count_letters(const char* str, int& n_letters, int& n_digits, int& n_other) {
	for (int i = 0; i < strlen(str); i++) {
		if ((int)str[i] <= 57 and (int)str[i] >= 48)
			n_digits++;
		else if (((int)str[i] <= 90 and (int)str[i] >= 65) or ((int)str[i] <= 122 and (int)str[i] >= 97))
			n_letters++;
		else
			n_other++;
	}
}

int main() {
	char str[20]; //= "hf1 v90. :1!";
	int a = 0;
	int b = 0;
	int c = 0;

	gets(str);
	count_letters(str, a, b, c);
	cout << "Кол-во букв: " << a << "\nКол-во цифр: " << b << "\nКол-во других символов: " << c << endl;
}