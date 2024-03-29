#include <iostream>
#include <utility>
#include <vector>
#include <cmath>

using std::cout, std::endl, std::pair, std::vector;

vector<pair<int, int>> factorization(int n) {
    if (n == 1) {
        return vector<pair<int,int>>{{1, 1}};
    }
    int d = 2;
    int c;
    vector<pair<int, int>> result;
    
    while(n != 1) {
        c = 0;
        while(n % d == 0) {
            c++;
            n /= d;
        }
        if (c)
            result.push_back(pair{d, c});
        d++;
    }
    return result;
}

std::ostream& operator<<(std::ostream& out, pair<int,int> p) {
    out << "{" << p.first << ", " << p.second << "}";
    return out;
}

std::ostream& operator<<(std::ostream& out, vector<pair<int,int>> v) {
    out << "{";
    size_t size = v.size();
    for(int i = 0; i < size; ++i) {
        out << v[i] << (i == size - 1 ? "}" : ", ");
    }
    return out;
}

int main() {
        vector<pair<int, int>> res = factorization(60);
        cout << res << endl;
        res = factorization(626215995);
        cout << res << endl;
        res = factorization(107);
        cout << res << endl;
        res = factorization(1);
        cout << res << endl;
}
