#include <iostream>
#include <string>
#include <utility>
#include <vector>

using std::string, std::pair, std::cout, std::endl, std::vector;

template <typename T>
T maximum(const vector<T>& v) {
    T max{};
    for(int i = 0, size = v.size(); i < size; ++i) {
        if (v[i] > max)
                max = v[i];
    }
    return max;
}

int main() {
    vector<int> int_v {1,3,5,3,23,113,34,54};
    cout << maximum(int_v) << endl;
    vector<float> float_v {1.5,5.64,5.67,45.65,113,67.5,98.12};
    cout << maximum(float_v) << endl;
    vector<string> string_v {"aaaa", "dfg", "dsfdgjb", "meow", "dsfewvcv", "klafdn"};
    cout << maximum(string_v) << endl;
    vector<pair<int, int>> pair_v {
            {113, 1},
            {12, 3},
            {45, 34},
            {113, 113},
            {112, 12233}
    };
    pair<int, int> res = maximum(pair_v);
    cout << "(" << res.first << ", " << res.second << ")" << endl;
}
