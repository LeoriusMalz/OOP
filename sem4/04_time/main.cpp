#include <iostream>
#include "time.h"
#include <string_view>
#include <string>
#include <vector>

using std::cout, std::endl, std::string, std::string_view, std::vector;

int main()
{
    string t1s = "23:59:59";
    string_view t1sv = t1s;
    string t2s = "23:59:59";
    string_view t2sv = t2s;

    Time t1 = t1sv;
    Time t2 = t2sv;
    cout << t1 + t2 << endl;

    string tss = "23:59:59 23:59:59 23:59:59";
    string_view tssv = tss;
    vector < Time > tsv = getTimesFromString(tss);
    for (int i = 0, size = tsv.size(); i < size; ++i) {
	cout << tsv[i] << endl;
    }
    cout << sumTimes(tsv) << endl;
}
