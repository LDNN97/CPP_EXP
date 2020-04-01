#include <iostream>
#include <vector>
#include <numeric>      // std::iota
#include <algorithm>    // std::sort, std::stable_sort
#include <fstream>

using namespace std;

template <typename T>

vector<size_t> sort_indexes(const vector<T> &v) {
    vector<size_t> idx(v.size());
    iota(idx.begin(), idx.end(), 0);
    stable_sort(idx.begin(), idx.end(), [&v](size_t i1, size_t i2) {return v[i1] < v[i2];});
    return idx;
}

constexpr int fibonacci(const int n) {
    return  n == 1 || n == 2 ? 1 : fibonacci(n-1) + fibonacci(n-2);
}

int main() {
//    vector<int> v(30);
//    v = {-11, -11, -11, -11, -11, -11,-11, -11, -11, -11, -11, -11,-11, -11, -11, -11, -11, -11,-11, -11, -11, -11, -11, -1,-11, -11, -11, -11, -11, -11};
//    for (auto i: sort_indexes(v)) {
//        cout << i << " " << v[i] << endl;
//    }
//
//    for (int i = 0; i < 10; i++) {
//        string file = "test/Aster.txt";
//        char num = static_cast<char>(i+'0');
//        cout << num << endl;
//        file.insert(10, 1, num);
//        ofstream fil(file);
//        fil << i << endl;
//        fil.close();
//    }
//    int len = 10;
//    char str[len];
    cout << fibonacci(10) << endl;

}
