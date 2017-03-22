/*****************************************************************
Name : 
Date : 2017/03/02
By   : CharlotteHonG
Final: 2017/03/18

1. 為什麼 const 版本的找不到函式
2. 如何讓 .pri() 連續呼叫
*****************************************************************/
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Arr {
public:
    Arr(int len=5):arr(len){
        for(unsigned i = 0; i < arr.size(); ++i) {
            arr[i]=i+1;
        }
    }
    // 印出
    void pri(string name=""){
        cout << name << " = ";
        for(auto&& i : arr) {
            cout << i << ", ";
        }cout << endl;
        // static_cast<Arr const &>(*this).pri();
    }
    // void pri(string name="") const{
    //     cout << name << " = ";
    //     for(auto&& i : arr) {
    //         cout << i << ", ";
    //     }cout << endl;
    // }
    // 重載下標符號
    int & operator[](size_t idx){
        return const_cast<int&>(static_cast<const Arr&>(*this)[idx]);
    }
    const int & operator[](size_t idx) const{
        return arr[idx];
    }
    // 重載+=符號
    Arr & operator+=(Arr const &rhs){
        for(unsigned i = 0; i < arr.size(); ++i)
            (*this)[i] += rhs[i];
        return (*this);
    }
private:
    vector<int> arr;
};
// 重載+符號(全域函式)
Arr operator+(Arr const &lhs, Arr const &rhs){
    return Arr(lhs) += rhs;
}
/*==============================================================*/
int main(int argc, char const *argv[]){
    Arr a;
    a.pri();

    Arr const b;
    b.pri();

    // b.pri()[0];
    // b.pri().pri();

    return 0;
}
/*==============================================================*/