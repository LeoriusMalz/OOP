#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

int string_sum(const string& str) {
    int res = 0;
    int x;
    int n = str.size();
    int i = 0;
    while (i < n) {
       switch (str[i]) {
            case '[':
            case ',' : 
                    sscanf((str.c_str()) + i + 1, "%d", &x);
                    res += x;
                    break;
            case ']' :
                    return res;
            case ' ':
                    break;
            default:
                    break;
       } 
       ++i;
    }
    return -1;
}

int main() {
    string meow;
    getline(cin, meow);
    cout << string_sum(meow) << endl;
}
