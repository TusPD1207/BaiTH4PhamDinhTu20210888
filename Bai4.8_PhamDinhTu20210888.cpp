/*
Bài tập 4.8: Viết các hàm thực hiện các phép giao và hợp của hai tập hợp mờ được biểu diễn bằng map.Trong đó mỗi phần tử được gán cho một số thực trong đoạn [0..1] biểu thị độ thuộc của phần tử trong tập hợp, với độ thuộc bằng 1 nghĩa là phần tử chắc chắn thuộc vào tập hợp và ngược lại độ thuộc bằng 0 nghĩa là phần tử chắc chắn không thuộc trong tập hợp.
Phép giao và hợp của 2 tập hợp được thực hiện trên các cặp phần tử bằng nhau của 2 tập hợp, với độ thuộc mới được tính bằng phép toán min và max của hai độ thuộc.
*/
// #include <iostream>
// #include <map>
// using namespace std;

template<class T>
map<T, double> fuzzy_set_union(const map<T, double> &a, const map<T, double> &b) {
map<T, double> c;
    for(auto v : a){
        int index = 0;
        for(auto u : b){
            if(v.first == u.first){//nếu thành phần đầu bằng nhau
                c.insert({v.first, max(v.second, u.second)});
                //in ra phần tử với thành phần thứ 2 là max của 2 thành phần con
                index++;
                break;
            }
        }
        if(index == 0) c.insert({v.first, v.second});
        //in ra phần tử u, v nếu thành phần đầu không bằng nhau
    }

    for(auto v : b){//đổi vị trí của hai map, làm ngược lại
        int index = 0;
        for(auto u : a){
            if(v.first == u.first){
                c.insert({v.first, max(v.second, u.second)});
                index++;
                break;
            }
        }
        if(index == 0) c.insert({v.first, v.second});
    }
    return c; 
}

template<class T>
map<T, double> fuzzy_set_intersection(const map<T, double> &a, const map<T, double> &b) {
    map<T, double> c;

    for(auto v : a){
        for(auto u : b){
            if(v.first == u.first){//nếu hai thành đầu giống nhau 
                c.insert({v.first, min(v.second, u.second)});
                //in ra thành phần thứ hai là min của 2 thành phần con
                break;
            }
        }
    }

    return c;
}

// template<class T>
// void print_fuzzy_set(const std::map<T, double> &a) {
//     cout << "{ ";
//     for (const auto &x : a) {
//         std::cout << "(" << x.first << ", " << x.second << ") ";
//     }
//     cout << "}";
//     std::cout << std::endl;
// }

// int main() {
//     std::map<int, double> a = {{1, 0.2}, {2, 0.5}, {3, 1}, {4, 0.6}, {5, 0.7}};
//     std::map<int, double> b = {{1, 0.5}, {2, 0.4}, {4, 0.9}, {5, 0.4}, {6, 1}};
//     std::cout << "A = "; print_fuzzy_set(a);
//     std::cout << "B = "; print_fuzzy_set(b);
//     std::map<int, double> c = fuzzy_set_union(a, b);
//     std::map<int, double> d = fuzzy_set_intersection(a, b);
//     std::cout << "Union: "; print_fuzzy_set(c);
//     std::cout << "Intersection: "; print_fuzzy_set(d);
// }
