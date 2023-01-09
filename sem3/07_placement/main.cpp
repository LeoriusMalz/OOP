#include <iostream>
#include "miptstring.cpp"

using std::cout, std::endl;

int main() {
    mipt::String stack{"Cat"};
    cout << stack << endl;

    mipt::String* heap = new mipt::String{"Dog"};
    cout << *heap << endl;

    char *x = (char*)malloc(sizeof(mipt::String));
    mipt::String* px = new(x) mipt::String{"Elephant"};

    cout << *px << endl;

    px->~String();
    free(px);
    delete heap;

}
