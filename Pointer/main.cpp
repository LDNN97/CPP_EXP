//1
//
//#include<iostream>
//#include<armadillo>
//
//using namespace std;
//
//int sum(int* begin, int* end) {
//    int total = 0;
//    for (int *ite = begin; ite != end; ite++)
//        total += *ite;
//    return total;
//}
//
//int main() {
//    int a[10];
//    for (int i = 0; i < 10; i++)
//        a[i] = i;
//    cout << (a) << endl;
//    cout << (a + 10) << endl;
//    cout << sum(a, a+10) << endl;
//
//}

// 2

//#include<iostream>
//
//using namespace std;
//
//struct Point{
//    int x, y;
//    explicit Point(int x = 0, int y = 0): x(x), y(y) {}
//};
//
//Point operator + (const Point &A, const Point &B){
//    return Point(A.x + B.x, A.y + B.y);
//}
//
//ostream &operator << (ostream &out, const Point &p){ //Todo: why &operator
//    out << "(" << p.x << "," << p.y << ")";
//    return out;
//}
//
//int main() {
//    Point a, b(1, 2);
//    a.x = 3;
//    cout << a + b << endl;
//    return 0;
//}

//3
//#include <iostream>
//
//using namespace std;
//
//int main(){
//    int* a = new int;
//    *a = 1;
//    for (int i = 0; i < 1; i++) {
//        int * b = new int;
//        *b = i;
//        delete a;
//        a = b;
//    }
//    cout << *a << endl;
//    delete a;
//}
//

// 3
#include <iostream>
#include <string>

using namespace std;

int main() {
    string map[2];
    map[0] = map[0] + " ";
    map[0] = map[0] + "*";
    string a(10, ' ');
    map[0] = map[0] + a;
    map[0] += "1";
    cout << map[0] << endl;
    cout << map[1] << endl;
    map[0].clear();
}

//
//#include <iostream>
//#include <vector>
//
//using namespace std;
//
//int main() {
//    auto v = new vector<int>;
//    cout << v->size() << endl;
//    int i = 0;
//    unsigned int a = -1;
//    cout << (a > 1) << endl;
////    for (int i = 0; i < v->size() - 1; i++)
////        cout << i << endl;
//}
