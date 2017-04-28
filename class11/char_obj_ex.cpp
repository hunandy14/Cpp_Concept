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
    } c += "\n\0";
    cout << endl;
    c.pri(); // print modified c

    c.resize(3);
    c.pri();
    c.resize(4);
    c += 'D';
    c.pri();
    return 0;
    return 0;
}
//================================================================
