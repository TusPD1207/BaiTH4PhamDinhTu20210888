/*
Bài tập 4.11: Bảo vệ lâu đài 
Bức tường bao quanh một lâu đài nọ được cấu thành từ n đoạn tường được đánh số từ 1 đến n. Quân giặc lên kế hoạch 
tấn công lâu đài bằng cách gửi ai tên giặc đánh vào đoạn tường thứ i. Để bảo vệ lâu đài có tất cả s lính. 
Do các đoạn tường có chất lượng khác nhau nên khả năng bảo vệ tại các đoạn tường cũng khác nhau. 
Cụ thể tại đoạn tường thứ i, mỗi lính có thể đẩy lùi tấn công của ki tên giặc.
Giả sử đoạn tường thứ i có xi lính. Khi đó nếu số tên giặc không vượt quá xi×ki thì không có tên giặc nào lọt 
vào được qua đoạn tường này. Ngược lại sẽ có ai−xi×ki tên giặc lọt vào lâu đài qua đoạn tường này.
Yêu cầu hãy viết chương trình phân bố lính đứng ở các đoạn tường sao cho tổng số lính là s và tổng số lượng tên 
giặc lọt vào lâu đài là nhỏ nhất.
*/
#include<bits/stdc++.h>
using namespace std;
struct data {
    int ai;
    int ki;
    data(int ai, int ki){
        this->ai = ai;
        this->ki = ki;
    } //khai báo trường chứa thông tin số quân giặc, sức tấn công của mỗi quân lính tại tường thứ i
};
struct compare{
    bool operator() (data a, data b){
        int ra, rb;
        
        if(a.ai <= a.ki) ra = a.ai;
        else ra = a.ki;

        if(b.ai <= b.ki) rb = b.ai;
        else rb = b.ki;
        return ra < rb;
    }//khai báo trường so sánh
};

int n, s, kill_enemy, total_enemy;
priority_queue<data, vector<data>, compare> p_q; //khai báo các hàm và biến cần thiết

void input(){
    cin >> n >> s;
    kill_enemy = 0;
    total_enemy = 0;
    for(int i=0; i<n; i++){
        int tmp1, tmp2;
        cin >> tmp1 >> tmp2;
        total_enemy += tmp1; //tổng số quân địch
        p_q.push(data(tmp1, tmp2));
    }
}

void solve(){ //hàm lưu trữ thông tin xử lý quân địch
    while(!p_q.empty() && s>0){//lặp đến khi hàng đợi p_q trống và số lượng lính còn lớn hơn 0
        data inf = p_q.top(); p_q.pop();//lấy phần tử đầu tiên gán cho inf và loại bỏ khỏi hàng đợi

        if(inf.ai <= inf.ki){//nếu số lượng quân địch nhỏ hơn khả năng tiêu diệt
            kill_enemy += inf.ai; //thêm ai quân địch vào số địch đã bị tiêu diệt
        } else {
            int nenemy = inf.ai - inf.ki;//số lượng quân địch còn lại
            p_q.push(data(nenemy, inf.ki));
            kill_enemy += inf.ki;//chỉ tiêu diệt được k1 quân địch
        }

        s -= 1; //giảm số lượng lính
    }
}

int calc_enemy(){ //tính toán số lượng quân địch còn lại sau thuật toán
    return total_enemy - kill_enemy;
}

int main(){
    input();
    solve();
    cout << calc_enemy();
    return 0;
}
