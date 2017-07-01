/*****************************************************************
Name : 
Date : 2017/07/01
By   : CharlotteHonG
Final: 2017/07/01
*****************************************************************/
#include <iostream>
using namespace std;

class Base{
public:
    Base(int i): num(i){}
    virtual ~Base(){}
public:
    // friend Base operator+(Base lhs, Base& rhs);
    Base& operator+=(Base& rhs){
        this->num += rhs.num;
        return (*this);
    }
    operator int&(){
        return num;
    }
private:
    int num;
};
inline Base operator+(Base lhs, Base& rhs){
    return lhs += rhs;
}


class Int_A: public Base {
public:
    Int_A(int i): Base(i){}
};
class Int_B: public Base {
public:
    Int_B(int i): Base(i){}
};


int main(int argc, char const *argv[]){
    Int_A a(1), b(2);
    cout << a+b << endl;
    Int_B c(3), d(4);
    cout << c+d << endl;
    return 0;
}