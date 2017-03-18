/*****************************************************************
Name : 
Date : 2017/03/06
By   : CharlotteHonG
Final: 2017/03/06
*****************************************************************/
#include <iostream>
#include <numeric>
using namespace std;

class List{
public:
    // 建構子
    List(size_t len=3): len(len){
        this->list = new int[len];
        // 初始化資源
        iota(list,list+len,1);
    }
    // 複製建構子
    // List(const List & rhs);
    // 解構子
    ~List(){
        delete [] this->list;
    }
public:
    // 印出
    List & pri(string name=""){
        if(name != "")
            cout << name << " = ";
        for(unsigned i = 0; i < this->len; ++i) {
            cout << "  " << (*this).list[i] << ", ";
        } cout << endl;
        return (*this);
    }
public:
    // 重載賦值符號
    // List & operator=(const List & rhs);
public:
    int* list;
    size_t len;
};
/*==============================================================*/
int main(int argc, char const *argv[]){
    List a(2);
    List b=a;
    
    a.pri("  a");
    b.pri("  b");

    // ab 同時被修改
    cout << "a_b" << endl;
    a.list[0]=7;
    a.pri("  a");
    b.pri("  b");


    // abc 同時被修改
    cout << "abc" << endl;
    List c(4);
    c.pri("  c"); 
    c=a;
    a.list[0]=8;
    a.pri("  a");
    b.pri("  b");
    c.pri("  c");

    return 0;
}
/*==============================================================*/
// 複製建構子
// List::List(const List & rhs): len(rhs.len){
//     this->list = new int[len];
//     // 複製
//     for(unsigned i = 0; i < len; ++i)
//         (*this).list[i] = rhs.list[i];
// }

// 重載賦值符號
// #include "operator_euq2.cpp"