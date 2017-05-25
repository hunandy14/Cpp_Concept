/*****************************************************************
Name : 
Date : 2017/05/25
By   : CharlotteHonG
Final: 2017/05/25
*****************************************************************/
#include <iostream>
using namespace std;

    class Demo{
    public:
        explicit Demo(int i): len(i){}
        explicit operator int&(){return len;}
        // int to_int(){
        //     return len;
        // }
        int len;
    };

void fun(Demo i) {
    
}
//================================================================
int main(int argc, char const *argv[]){
    Demo a(10);
    // fun( (int)a );

    int i=10;
    fun( Demo(i) );

    Str a;
    char s=a;

    return 0;
}
//================================================================
