/*
Bài tập 4.5: Viết hàm void dfs(vector< list<int> > adj) thực hiện thuật toán DFS không sử dụng đệ quy trên đồ thị biểu diễn bằng danh sách kề. Đồ thị có n đỉnh được đánh số từ 1 đến n. Thuật toán DFS xuất phát từ đỉnh 1. Các đỉnh được thăm theo thứ tự ưu tiên từ trái sang phải trong danh sách kề. Yêu cầu hàm trả ra thứ tự các đỉnh được thăm (những đỉnh không thể thăm từ đỉnh 1 thì không phải in ra).
*/
void dfs(vector< list<int> > adj) {
    stack<int> S;
    vector<bool> visited(adj.size());
    S.push(1); // Bắt đầu từ đỉnh số 1
    while (!S.empty()) {//nếu trong ngăn xếp không rỗng
        int u=S.top(); //u là đỉnh ngăn xếp
        if (!visited[u]){
            visited[u] = true;//nếu chưa thăm u, thì thăm u rồi in ra u
            std::cout<< u << std::endl;
        }
        if (!adj[u].empty()){ //nếu có đỉnh kề u
            int v=adj[u].front(); adj[u].pop_front(); //xoá phần tử 
            if(!visited[v]){
                S.push(v);//thêm phần tử vào ngăn xếp
            }
        }else { S.pop();}//nếu không thì xoá phần tử khỏi ngăn xếp
    }
}
