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
    friend void fun2();
protected:
    int num;
};


class B: public A {
public:
    B(int b): A(b){}
    void fun(){
        cout << "Bnum=" << num << endl;
    }
    int num2;
};

class C: public A {
public:
    C(int c): A(c){}
    void fun(){
        cout << "Cnum=" << num << endl;
    }
    int num3;
};

// void fun2(A & a){
//     cout << "a.num=" << a.num << endl;
// }

void fun(A* p){
    p->fun();
}
//================================================================
int main(int argc, char const *argv[]){
    A* p1 = new B(1);
    A* p2 = new C(2);
    
    fun(p1);
    fun(p2);
    


    return 0;
}
//================================================================
