/*
Bài tập 4.2: Một điểm trong không gian 2 chiều được biểu diễn bằng pair. 
Hãy viết hàm tính diện tích tam giác theo tọa độ 3 đỉnh.
*/
// #include <iostream>
// #include <cmath>
// #include <iomanip>
// #include <utility>
// using namespace std;
// using Point = pair<double, double>;
    
    double distance(Point a, Point b){
    return sqrt((a.first - b.first)*(a.first - b.first) + (a.second - b.second)*
    (a.second - b.second)); //tính khoảng cách, hay là độ dài cạnh tam giác
}

double area(Point a, Point b, Point c) {
    double ab = distance(a,b);
    double bc = distance(b,c);
    double ca = distance(c,a);

    double p = (ab + bc + ca) /2;
    return sqrt(p * (p-ab) * (p-bc) * (p-ca)); //sử dụng công thức Heron tính S
}

// int main() {
//     cout << setprecision(2) << fixed;
//     cout << area({1, 2}, {2.5, 10}, {15, -5.25}) << endl;
//     return 0;
// }
