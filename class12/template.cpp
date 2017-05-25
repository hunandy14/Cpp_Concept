/*****************************************************************
Name : 
Date : 2017/05/25
By   : CharlotteHonG
Final: 2017/05/25
*****************************************************************/
#include <iostream>
using namespace std;

template<typename T>
void fun(T num) {
    cout << "num=" << num << endl;
}

template<class T>
class Demo{
public:
    Demo(){

    }
    ~Demo(){}

    T fun(T a){
        
    }
private:
    T a;
    int len;
};
//================================================================
int main(int argc, char const *argv[]){
    fun( float(10.1) );

    Str<int> a(100);

    a += 10;

    return 0;
}
//================================================================
