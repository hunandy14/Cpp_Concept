/*****************************************************************
Name : 
Date : 2017/07/01
By   : CharlotteHonG
Final: 2017/07/01
*****************************************************************/
#include <iostream>
using namespace std;

class Base {
public:
    Base(){}
    virtual ~Base(){}
public:
    virtual void fun() = 0;
};

class A: public Base{
public:
    A(){}
    void fun(){
        cout << "A" << endl;
    }
};
class B: public Base{
public:
    B(){}
    void fun(){
        cout << "B" << endl;
    }
};




void fun(Base* p) {
    p->fun();
}

int main(int argc, char const *argv[]){
    fun(new A); // print A
    fun(new B); // print B
    return 0;
}
