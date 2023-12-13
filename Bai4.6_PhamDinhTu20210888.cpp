/*
Bài tập 4.6: Viết hàm void bfs(vector< list<int> > adj) thực hiện thuật toán BFS không sử dụng đệ quy trên đồ thị biểu diễn bằng danh sách kề. Đồ thị có n đỉnh được đánh số từ 1 đến n. Thuật toán BFS xuất phát từ đỉnh 1. Các đỉnh được thăm 
theo thứ tự ưu tiên từ trái sang phải trong danh sách kề. Yêu cầu hàm trả ra thứ tự các đỉnh được thăm (những đỉnh không thể thăm từ đỉnh 1 thì không phải in ra).
*/
void bfs(vector< list<int> > adj) {
    queue<int> Q;
    vector<bool> visited(adj.size());
    Q.push(1); // Bắt đầu từ đỉnh số 1
    while (!Q.empty()) {//nếu hàng đợi không rỗng
        int u=Q.front();  //chọn u là phần tử đầu hàng đợi
        if (!visited[u]){
            visited[u] = true; //nếu chưa thăm u, thì in ra u
            std::cout<< u << std::endl;
        }
        if (!adj[u].empty()){//nếu u có đỉnh kề
            int v=adj[u].front(); adj[u].pop_front();//pop đỉnh ở kề u
            if(!visited[v]){
                Q.push(v);//thêm v vào hàng đợi
            }
        }else { Q.pop();}//loại bỏ phần tử khỏi hàng đợi
    }
}
