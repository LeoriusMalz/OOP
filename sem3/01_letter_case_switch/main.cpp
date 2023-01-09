#include <iostream>
#include <string>
#include <cctype>

using namespace std;

string letter_case_switch(const string & str)
{
    string result = str;
    if (str.size() == 0)
	return result;
    result[0] =
	isupper(result[0]) ? tolower(result[0]) : toupper(result[0]);
    return result;
}

int main()
{
    string meow;
    cin >> meow;
    cout << letter_case_switch(meow) << endl;
}
