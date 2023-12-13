/*
Bài tập 4.7: Viết các hàm thực hiện các phép giao và hợp của hai tập hợp được biểu diễn bằng set
*/
// #include <iostream>
// #include <set>
// using namespace std;

template<class T>
set<T> set_union(const set<T> &a, const set<T> &b) {
set<T> c;
    for(T v : a){
        c.insert(v); //phần tử thuộc a, thêm vào set hợp
    }
    for(T v : b){
        c.insert(v); //phần tử thuộc b, thêm vào set hợp
    }
    return c;//in ra set hợp của set a và set b
}

template<class T>
set<T> set_intersection(const set<T> &a, const set<T> &b) {
set<T> c;
    for(T v : a){
        int index = 0;
        for(T u : b){
            if(v == u) index++; //nếu hai phần tử giống nhau, cộng index
        }
        if(index != 0) c.insert(v);//nếu index khác 0, thêm vào set giao
    }
    return c;//in ra set giao của hai set a và set b
}

// template<class T>
// void print_set(const std::set<T> &a) {
//     for (const T &x : a) {
//         std::cout << x << ' ';
//     }
//     std::cout << std::endl;
// }

// int main() {
//     std::set<int> a = {1, 2, 3, 5, 7};
//     std::set<int> b = {2, 4, 5, 6, 9};
//     std::set<int> c = set_union(a, b);
//     std::set<int> d = set_intersection(a, b);
    
//     std::cout << "Union: "; print_set(c);
//     std::cout << "Intersection: "; print_set(d);

//     return 0;
//}
