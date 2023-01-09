#include <iostream>
#include "miptstring.h"
#include "miptstringview.h"
using namespace std;

int main() {
    mipt::String a = "abcd";
    mipt::String b = "abce";
    mipt::StringView av = a;
    mipt::StringView bv = b;
    //cout << (b < a) << endl;
    //cout << (bv < av) << endl;
    cout << av.substr(1,10) << endl; 
    av.remove_suffix(2);
    cout << av << endl;
    mipt::String meow = av;
    cout << "sv to string: " << meow << endl;
}
