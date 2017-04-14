/*****************************************************************
Name : 
Date : 2017/03/06
By   : CharlotteHonG
Final: 2017/03/06

1. 為何會同時被修改
*****************************************************************/
#include <iostream>
#include <numeric>
#include <algorithm>
using namespace std;

class List{
public:
    // 建構子
    template<class... U>
    List(U... args): len(sizeof...(args)), 
        list(new int[len]{args...}){}
    List(size_t len=0): len(len), list(new int[len]){
        // 初始化資源
        iota(list,list+len,1);
    }
    // 解構子
    ~List(){
        delete [] this->list;
    }
public:
    // 複製建構子
    List(const List & rhs);
    // 重載賦值符號
    List & operator=(const List & rhs);
    // 移動建構子
    List(List && rhs): len(rhs.len), list(nullptr){
        (*this) = std::move(rhs);
    }
    // 移動函式
    List & operator=(List && rhs){
        (*this).move_copy(rhs);
        return (*this);
    }
    // 移動函式
    List & move_copy(List & rhs){
        this->~List();
        this->len = rhs.len;
        this->list = rhs.list;
        rhs.list = nullptr;
        rhs.len = 0;
        return (*this);
    }
public:
    // 印出
    List & pri(string name=""){
        if(name != "")
            cout << name << " = ";
        for(unsigned i = 0; i < this->len; ++i) {
            cout << (*this).list[i] << ", ";
        } cout << endl;
        return (*this);
    }
public:
    size_t len;
    int* list;
};
/*==============================================================*/
int main(int argc, char const *argv[]){
    List a(size_t(4));
    List b(size_t(2));

    b.move_copy(a);
    b.pri("b");
    a.pri("a");

    List c;
    c=std::move(b);
    b.pri("b");

    List d=std::move(c);
    c.pri("c");
    d.pri("d");
    return 0;
}
/*==============================================================*/
// 複製建構子
List::List(const List & rhs): len(rhs.len), list(new int[len]){
    // 複製
    cout << "Copy ctor" << endl;
    std::copy_n(rhs.list, rhs.len, list);
}
// 複製函式
List & List::operator=(const List & rhs){
    cout << "Copy" << endl;
    // 相同則離開
    if(this == &rhs)
        return (*this);
    // 清除原始資源
    this->~List();
    // 重建資源
    this->len = rhs.len;
    this->list = new int[len];
    // 複製
    std::copy_n(rhs.list, rhs.len, list);
    return (*this);
}