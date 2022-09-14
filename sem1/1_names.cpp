#include <stdio.h>

namespace myspace {
	void print_n_times(char str[10], int n = 10) {
		for (int i = 0; i < n; i++)
			printf("%s\n", str);
	}
}

int main() {
	char str[10] = "Hello";
	
	gets(str);
	myspace::print_n_times(str);
}