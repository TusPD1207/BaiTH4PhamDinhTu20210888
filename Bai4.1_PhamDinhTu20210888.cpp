/*
Bài tập 4.1: Đảo ngược một danh sách liên kết đơn 
Hãy hoàn thiện các hàm thao tác trên một danh sách liên kết: 
Thêm một phần tử vào đầu danh sách liên kết, in danh sách và đảo ngược danh sách liên kết (yêu cầu độ phức tạp thời gian O(N) và chi phí bộ nhớ dùng thêm O(1))
*/
#include <iostream> 
using namespace std;
struct Node { 
    int data; 
    Node* next;
    Node(int data) {
        this->data = data;
        next = NULL;
    } //Khai báo trường Node để định nghĩa phần tử trong danh sách
};

// push a new element to the beginning of the list
Node* prepend(Node* head, int data) {
    Node* new_node = new Node(data);
    new_node->next = head;
    head = new_node; //thêm một phần tử vào đầu danh sách 
    return head; 
}

// print the list content on a line
void print(Node* head) {
    Node *tmp = head;
    while(tmp != NULL){ 
        printf("%d ",tmp->data);
        tmp = tmp->next; //in danh sách khi mà phần tử khác NULL, dừng nếu NULL
    }
    cout << endl;
}

// return the new head of the reversed list
Node* reverse(Node* head) {
    Node* current = head->next;
    Node* prev = head; prev->next = NULL;
    Node* next = NULL;

    while(current != NULL){
        next = current->next; //Đảo ngược vòng tròn
        current->next = prev;
        prev = current;
        current = next;
    }
    head = prev;
    return head; //Đảo phần tử thứ nhất cho phần tử cuối
}
  
int main() {
    int n, u;
    cin >> n;
    Node* head = NULL;
    for (int i = 0; i < n; ++i){
        cin >> u;
        head = prepend(head, u);
    } 
    cout << "Original list: ";
    print(head);
    head = reverse(head);
    cout << "Reversed list: ";
    print(head);
    return 0; 
}
