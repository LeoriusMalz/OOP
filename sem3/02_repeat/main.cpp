#include <iostream>
#include <string>
#include <string_view>

using namespace std;

string repeat1(string_view s)
{
    return string {
    s}
    +string {
    s};
}

void repeat2(string & s)
{
    s += s;
}

void repeat3(string * s)
{
    *s += *s;
}

string *repeat4(string_view s)
{
    string *result = new string;
    *result = string {
    s} +string {
    s};
    return result;
}

int main()
{
    string meow;
    cin >> meow;

    cout << "test of repeat1:" << endl << repeat1(meow) << endl;

    repeat2(meow);
    cout << "test of repeat2:" << endl << meow << endl;

    repeat3(&meow);
    cout << "test of repeat3:" << endl << meow << endl;

    cout << "test of repeat4:" << endl << *repeat4(meow) << endl;
}
