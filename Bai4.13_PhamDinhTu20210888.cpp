/*
Bài 4.13: 
Cho một xâu nhị phân độ dài n. 
Hãy viết chương trình đếm số lượng xâu con chứa số ký tự 0 và số ký tự 1 bằng nhau.
*/
#include<bits/stdc++.h>
using namespace std;
const int MAX = 1000000;
string str;
int n, cnt;
int slg0[MAX]; // số lượng bit 0 trong khoảng từ 0 tới i
int slg1[MAX]; // số lượng bit 1 trong khoảng từ 0 tới i

void input(){//nhập dữ liệu
    cnt = 0;//biến đếm
    cin >> str;//nhập xâu nhị phân
    n = str.length();

    for(int i=0; i<n; i++){
        if(i==0){ //kiểm tra vị trí đầu tiên của xâu
            if(str[i] == '0'){//nếu giá trị của str[i] là bit 0
                slg0[i] = 1;//đặt giá trị của slg0 là 1
                slg1[i] = 0;//đặt giá trị của slg1 là 0
            } else {
                slg0[i] = 0;
                slg1[i] = 1;//và ngược lại
            }
            continue;// tiếp tục vòng lặp
        }
        //tiếp tục xử lý với i khác 0
        if(str[i] == '0'){ //nếu tại i là bit 0
            slg0[i] = slg0[i-1] + 1; //ta cập nhật giá trị slg0 theo giá trị trước đó 
            slg1[i] = slg1[i-1]; // còn slg1 giữ nguyên như trước đó
        } else {
            slg0[i] = slg0[i-1];
            slg1[i] = slg1[i-1] + 1; //làm tương tự như trên
        }
    }
}

void solve(){
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j = j + 2){//duyệt qua các đoạn con trong chuỗi
            if(i==0){
                if(slg0[j] == slg1[j]) cnt++;//nếu số lượng bit 0 và 1 bằng nhau, cộng thêm 1 vào cnt
            } else {
                int c0 = slg0[j] - slg0[i-1];//tính số bit 0 từ i đến j
                int c1 = slg1[j] - slg1[i-1];//tính số bit 1 từ i đến j

                if(c0 == c1) cnt++; //nếu số lượng bằng nhau, cộng thêm 1 vào cnt
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    input();
    solve();

    cout << cnt;
    return 0;
}