/*
Bài tập 4.4: Cho hai std::vector, hãy xóa hết các phần tử chẵn, sắp xếp giảm dần các số trong cả 2 vector và trộn lại thành một vector cũng được sắp xếp giảm dần.
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


void print_vector(const vector<int> &a) {
    for (int v : a) cout << v << ' ';
    cout << endl;
}

void delete_even(vector<int> &a) {
     a.erase(remove_if(a.begin(), a.end(),[](int x){return x%2==0;}), a.end());
}//nếu phần tử x chia hết cho 2, loại bỏ phần tử đó

void sort_decrease(vector<int> &a) {
     sort(a.rbegin(), a.rend());
}//sắp xếp phần tử theo thứ tự giảm dần

vector<int> merge_vectors(const vector<int> &a, const vector<int> &b) {
    vector<int> c;
    merge(a.begin(), a.end(), b.begin(), b.end(), back_inserter(c), greater<int>());
    return c;
}//gộp hai vector, sau đó sắp xếp một lần nữa

int main() {
    int m, n, u;
    std::vector<int> a, b;
    
    std::cin >> m >> n;
    for(int i = 0; i < m; i++){
        std:: cin >> u;
        a.push_back(u);
    }
    for(int i = 0; i < n; i++){
        std:: cin >> u;
        b.push_back(u);
    }

    delete_even(a);
    cout << "Odd elements of a: ";
    print_vector(a);

    delete_even(b);
    cout << "Odd elements of b: ";
    print_vector(b);

    sort_decrease(a);
    cout << "Decreasingly sorted a: ";
    print_vector(a);

    sort_decrease(b);
    cout << "Decreasingly sorted b: ";
    print_vector(b);

    vector<int> c = merge_vectors(a, b);
    cout << "Decreasingly sorted c: ";
    print_vector(c);
    return 0;
}
