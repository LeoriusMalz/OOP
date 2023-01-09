#include <iostream>
#include <string>

using namespace std;

void truncateToDot(string& s) {
    s.resize(s.find('.'));
    s.shrink_to_fit();
}

int main() {
    std::string a = "cat.dog.mouse.elephant.tiger.lion";
    std::string b = "wikipedia.org";
    std::string c = ".com";
    truncateToDot(a);
    truncateToDot(b);
    truncateToDot(c);

    cout << a << endl
         << b << endl
         << c << endl;
}
