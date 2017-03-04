/*****************************************************************
Name : 
Date : 2017/03/02
By   : CharlotteHonG
Final: 2017/03/02
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
    ~Arr(){
        // cout << "秆篶" << endl;
    }
    void pri(string name=""){
        cout << name << " = ";
        for(auto&& i : arr) {
            cout << i << ", ";
        }cout << endl;
    }
    // 更夹才腹
    int & operator[](size_t idx){
        // return const_cast<int&>(static_cast<const Arr&>(*this)[idx]);
        return arr[idx];
    }
    const int & operator[](size_t idx) const{
        return arr[idx];
    }
    // 更+=才腹
    Arr & operator+=(Arr const &rhs){
        for(unsigned i = 0; i < arr.size(); ++i)
            (*this)[i] += rhs[i];
        return (*this);
    }
private:
    vector<int> arr;
};
// 更+才腹(办ㄧΑ)
Arr operator+(Arr const &lhs, Arr const &rhs){
    return Arr(lhs) += rhs;
}

/*==============================================================*/
int main(int argc, char const *argv[]){
    Arr a, b, c;
    a.pri("first");
    // 更 +=
    a+=b;
    a.pri("a+=b");
    // 更 +
    a=b+c;
    a.pri("a=b+c");

    return 0;
}
/*==============================================================*/