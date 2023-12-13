/*
Bài tập 4.12: Cho một lược đồ gồm n cột chữ nhật liên tiếp nhau có chiều rộng bằng 1 và chiều cao lần lượt là 
các số nguyên không âm h1,h2,…,hn. 
Hãy xác định hình chữ nhật có diện tích lớn nhất có thể tạo thành từ các cột liên tiếp.
*/

#include<bits/stdc++.h>
using namespace std;

long long n;
vector<long long> vt;//chiều cao của từng cột chữ nhật
vector<long long> L; 
vector<long long> R; 
// vị trí bên trái và bên phải lớn nhất mà chiều cao của cột tại vị trí đó vẫn lớn hơn chiều cao của cột i

void inputData(){//hàm nhập dữ liệu
    cin >> n;
    vt.push_back(-1); //thêm giá trị -1 để xử lý các biên
    for(long long i=0; i<n; i++){
        long long tmp;
        cin >> tmp;
        vt.push_back(tmp);
    }
    vt.push_back(-1); 
}

void solve(){
    while(true){
        inputData();
        if(n==0) return;
        stack<long long> st; //theo dõi các cột chưa được xử lý
        L.resize(n+2);
        R.resize(n+2);//resize vector L và R để đủ không gian lưu trữ thông tin vị trí
        for(long long i=1; i<=n+1; i++){//dùng hàm for để tính toán vector
            while(!st.empty() && vt[i] < vt[st.top()]){//stack không rỗng và chiều cao i nhỏ hơn đỉnh stack
                L[st.top()] = i;//gán i cho L.[st.top()]
                st.pop();//loại bỏ đỉnh stack vì đã xử lý xong
            }
            st.push(i);//tiếp tục thực hiện vòng lặp
        }
        for(long long i=n; i>=0; i--){
            while(!st.empty() && vt[i] < vt[st.top()]){
                R[st.top()] = i;
                st.pop();
            }
            st.push(i);//làm như với vector L
        }
        long long maxh = 0;
        for(long long i=1; i<=n; i++){//tính diện tích lớn nhất được tạo thành sau khi xử lý, duyệt qua cột 
            long long h = (L[i] - R[i] -1)*vt[i];//chiều cao là phần trong ngoặc, chiều rộng là vt[i]
            if(h > maxh) maxh = h;//so sánh h với maxh
        }
        cout << maxh << endl; break;//in ra kết quả
        vt.erase(vt.begin(),vt.end());
        L.erase(L.begin(),L.end());
        R.erase(R.begin(),R.end());//xoá nội dung vector L, R để cho lần lặp tiếp theo
    }
}
int main(){
    solve();
    return 0;
}
