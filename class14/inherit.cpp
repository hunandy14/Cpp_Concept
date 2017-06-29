/*****************************************************************
Name : 
Date : 2017/06/29
By   : CharlotteHonG
Final: 2017/06/29
*****************************************************************/
#include <iostream>
using namespace std;

class A {
public:
    A(int a): num(a){}
    virtual ~A(){}
    virtual void fun(){
        cout << "num=" << num << endl;
    }
protected:
    int num;
};
class B: public A {
public:
    B(int b=1): A(b){}
    void fun(){
        cout << "Bnum=" << num << endl;
    }
    int num2;
};
class C: public A {
public:
    C(int c=2): A(c){}
    void fun(){
        cout << "Cnum=" << num << endl;
    }
    int num3;
};


void fun(A* p){
    p->fun();
}
//================================================================
int main(int argc, char const *argv[]){
    fun(new B);
    fun(new C);
    return 0;
}
//================================================================
