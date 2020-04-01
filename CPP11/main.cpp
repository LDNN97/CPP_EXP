//#include <iostream>
//#include <vector>
//#include <numeric>      // std::iota
//#include <algorithm>    // std::sort, std::stable_sort
//#include <fstream>
//
//using namespace std;
//
//template <typename T>
//
//vector<size_t> sort_indexes(const vector<T> &v) {
//    vector<size_t> idx(v.size());
//    iota(idx.begin(), idx.end(), 0);
//    stable_sort(idx.begin(), idx.end(), [&v](size_t i1, size_t i2) {return v[i1] < v[i2];});
//    return idx;
//}
//
//constexpr int fibonacci(const int n) {
//    return  n == 1 || n == 2 ? 1 : fibonacci(n-1) + fibonacci(n-2);
//}
//
//int main() {
////    vector<int> v(30);
////    v = {-11, -11, -11, -11, -11, -11,-11, -11, -11, -11, -11, -11,-11, -11, -11, -11, -11, -11,-11, -11, -11, -11, -11, -1,-11, -11, -11, -11, -11, -11};
////    for (auto i: sort_indexes(v)) {
////        cout << i << " " << v[i] << endl;
////    }
////
////    for (int i = 0; i < 10; i++) {
////        string file = "test/Aster.txt";
////        char num = static_cast<char>(i+'0');
////        cout << num << endl;
////        file.insert(10, 1, num);
////        ofstream fil(file);
////        fil << i << endl;
////        fil.close();
////    }
////    int len = 10;
////    char str[len];
//    cout << fibonacci(10) << endl;
//
//}

#include <iostream>
#include <string>

void reference(std::string& str) {
    std::cout << "左值" << std::endl;
}
void reference(std::string&& str) {
    std::cout << "右值" << std::endl;
}

int main()
{
    std::string lv1 = "string,"; // lv1 是一个左值
    // std::string&& r1 = lv1; // 非法, 右值引用不能引用左值
    std::string&& rv1 = std::move(lv1); // 合法, std::move可以将左值转移为右值
    std::cout << rv1 << std::endl; // string,

    const std::string& lv2 = lv1 + lv1; // 合法, 常量左值引用能够延长临时变量的生命周期
    // lv2 += "Test"; // 非法, 常量引用无法被修改
    std::cout << lv2 << std::endl; // string,string

    std::string&& lv3 = lv1 + lv2; // 合法, 右值引用延长临时对象生命周期

    reference(lv1 + lv2); // 输出左值

    return 0;
}