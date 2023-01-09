#include <iostream>
#include <string>
#include <string_view>

using namespace std;

int main() {
    int *x = new int{123};
    cout << *x << endl;

    string *str = new string{"Cats and Dogs"};
    cout << *str << endl;

    int *xs = new int[]{10, 20, 30, 40, 50};
    for (int i = 0; i < 5; ++i)
            cout << xs[i] << " ";
    cout << endl;

    string *strs = new string[]{"Cat", "Dog", "Mouse"};
    for (int i = 0; i < 3; ++i)
            cout << strs[i] << " ";
    cout << endl;

    string_view *str_views = new string_view[]{strs[0], strs[1], strs[2]};
    for (int i = 0; i < 3; ++i)
            cout << str_views[i] << " ";
    cout << endl;

    delete x;
    delete str;
    delete[] xs;
    delete[] strs;
    delete[] str_views;
}
