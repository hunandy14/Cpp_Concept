/*****************************************************************
Name : 
Date : 2017/04/27
By   : CharlotteHonG
Final: 2017/04/27
*****************************************************************/
#include <iostream>
#include <cstring>
using namespace std;

class Str{
public:
    Str(){}
    ~Str(){}
public:
    char* s;
};
//================================================================
int main(int argc, char const *argv[]){
    Str a="Hello World!";
    Str b=a;
    Str c;
    c = a+b; // c is "Hello World!Hello World!"

    // print c and modify c
    for (unsigned i = 0; i < c.size(); ++i){
        cout << c[i];
        c[i] = (i+65);
    }cout << endl;

    c.pri(); // print modified c
    return 0;
}
//================================================================
