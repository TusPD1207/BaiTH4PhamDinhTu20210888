/*
Bài tập 4.10: Search engine 
Xây dựng một máy tìm kiếm (search engine) đơn giản.
Cho N văn bản và Q  truy vấn. Với mỗi truy vấn, cần trả về văn bản khớp với truy vấn đó nhất. 
Ta coi văn bản có điểm số càng cao thì càng khớp với truy vấn.
*/ 
//Pham Dinh Tu 20210888
#include<bits/stdc++.h>
using namespace std;
int n, q;
vector< vector<string> > vector_train;
vector< vector<string> > vector_test;
vector<int> f_max; // tần suất xuất hiện từ xuất hiện nhiều nhất trong văn bản
map<string, int> df; // tính xem từ nằm trong bao nhiêu văn bản
map<pair<string, int>, int> fe; // tính xem từ xuất hiện bao nhiêu lần trong văn bản

//Tách chuỗi theo biểu thức chính quy
vector<string> split_string(string str){
    vector<string> vt;

    while (!str.empty()){ //nếu chuỗi không rỗng
        string tmp = str.substr(0, str.find(",")); //dùng chuỗi phụ để gán chuỗi phụ 
        int pos = tmp.find(" "); //dùng pos để định vị dấu cách, để tách chuỗi

        if(pos > tmp.size()) //khi đã đủ dấu cách
            vt.push_back(tmp);//chèn tmp vào cuối vector
        else {
            while(pos <= tmp.size()){
                tmp.erase(pos,1);//xoá pos
                pos = tmp.find(" ");//tiếp tục tiếp pos cho đến khi pos lớn hơn tmp.size()
            }
            vt.push_back(tmp);//chèn tmp vào cuối vector
        }
        if (str.find(",") > str.size()){
            break; //làm tương tự như phần trên
        } else {
            str.erase(0, str.find(",") + 1);
        }
    }

    return vt;
}

// Nhập dữ liệu
void input(){
    vector<string> document_train;
    vector<string> document_test;

    cin >> n;
    string str_tmp;
    getline(cin, str_tmp);

    for(int i=0; i<n; i++){
        string str_tmp;
        getline(cin, str_tmp);
        document_train.push_back(str_tmp);
    }

    cin >> q;
    getline(cin, str_tmp);
    for(int i=0; i<q; i++){
        string str_tmp;
        getline(cin, str_tmp);
        document_test.push_back(str_tmp);
    }

    for(string v : document_train){
        vector<string> element = split_string(v);

        vector_train.push_back(element);
    }

    for(string v : document_test){
        vector<string> element = split_string(v);

        vector_test.push_back(element);
    }
}

// Xử lý hàm trước
void pre_processing(){
    //Tính tần suất của từ xuất hiện nhiều nhất
    for(vector<string> str_tmp : vector_train){
        map<string, int> m;

        // thiết lập biến với chỉ số [số từ][tần suất]
        int max_f = 0;
        for(string word_tmp : str_tmp){
            map<string, int>::iterator ite = m.find(word_tmp);
            if(ite == m.end()){ // nếu từ này chưa xuất hiện
                m.insert({word_tmp, 1});
            } else {
                ite->second += 1;
            }

            max_f = max(m[word_tmp], max_f);
        }
        f_max.push_back(max_f);
    }
}

//tính xem từ xuất hiện bao nhiêu lần trong văn bản
int frequence_word_int_document_i(string word, int i){
    if(fe.find({word, i}) != fe.end()){ // nếu đã có trong kho find thì lấy kết quả và trả về
        return fe[{word, i}];
    }

    int index = 0;
    vector<string> str_tmp = vector_train[i];

    for(string v : str_tmp){
        if(word == v) index++;
    }

    fe.insert({{word, i}, index});
    return index;
}

// tính xem từ nằm trong bao nhiêu văn bản
int count_document_contain_word(string word){ // nếu đã có trong kho find thì lấy kết quả và trả về
    if(df.find(word) != df.end()){
        return df[word];
    }

    int index = 0;
    for(vector<string> str_tmp : vector_train){

        vector<string>::iterator ite = find(str_tmp.begin(), str_tmp.end(), word);
        if(ite != str_tmp.end()){
            index++;
        }
    }

    df.insert({word,index});
    return index;
}

// Dự đoán văn bản
int search_engine(vector<string> list_word){
    double score_max = -1000;
    int predict_label = -1;
    for(int i=0; i<n; i++){
        vector<string> list_word_train_doc = vector_train[i];

        double score = 0;
        for(string word : list_word){
            if(find(list_word_train_doc.begin(), list_word_train_doc.end(), word) == list_word_train_doc.end()){ // tu nay khong xuat hien trong van ban
                continue;
            } else {
                int ftd = frequence_word_int_document_i(word, i);
                int dft = count_document_contain_word(word);
                int maxfd = f_max[i];

                double tf_word = 0.5 + 0.5 * ((double) ftd / maxfd);
                double idf_word = log2((double) n / dft);

                score += tf_word * idf_word;
            }
        }

        if(score > score_max) {
            predict_label = i;
            score_max = score;
        }
    }

    return predict_label + 1;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    input();
    pre_processing();
    for(int i=0; i<q; i++)
        cout << search_engine(vector_test[i]) << endl; //thực hiện vector_test[i] với search engine

    return 0;
}
