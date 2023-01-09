#include <iostream>
#include <vector>
#include <span>

using std::cout, std::endl, std::vector, std::span;

vector<int> lastDigits1(const vector<int>& v) {
    vector<int> result;
    size_t size = v.size();
    for(int i = 0; i < size; ++i) {
        result.push_back(v[i] % 10);
    }
    return result;
}
void lastDigits2(vector<int>& v) {
    size_t size = v.size();
    for(int i = 0; i < size; ++i) {
        v[i] %= 10;
    }
}

void lastDigits3(vector<int>* pv) {
    size_t size = pv->size();
    for(int i = 0; i < size; ++i)
            (*pv)[i] %= 10;
}

void lastDigits4(span<int> sp) {
    size_t size = sp.size();
    for(int i = 0; i < size; ++i)
            sp[i] %= 10;
}

std::ostream& operator<<(std::ostream& out, const vector<int>& v) {
    cout << "[";
    size_t size = v.size();
    for(int i = 0; i < size; ++i)
        cout << v[i] << (i == size - 1 ? "]" : " ");
    return out;
}

int main() {
    vector<int> meow{1, 2, 3, 12, 45, 32,313123,3245};
    vector<int> result1 = lastDigits1(meow);
    cout << result1 << endl;

    vector<int> result2 = meow;
    lastDigits2(result2);
    cout << result2 << endl;

    vector<int> result3 = meow;
    lastDigits3(&result3);
    cout << result3 << endl;

    span<int> sp = meow;
    lastDigits4(sp);
    cout << meow << endl;
}
