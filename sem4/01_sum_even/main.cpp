#include <iostream>
#include <vector>

using std::cout, std::endl;

int sumEven(const std::vector<int>& v) {
    int sum = 0;
    size_t s = v.size();
    for (int i = 0; i < s; ++i)
            if (v[i] % 2 == 0)
                    sum += v[i];
    return sum;
}

int main() {
    std::vector<int> v {4, 8, 15, 16, 23, 42};
    cout << sumEven(v) << endl;
}
