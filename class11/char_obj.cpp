/*****************************************************************
Name : 
Date : 2017/04/27
By   : CharlotteHonG
Final: 2017/04/27
*****************************************************************/
#include <iostream>
using namespace std;

class Str{
public:
    Str();
    ~Str();
private:
    char* s;
};
//================================================================
int main(int argc, char const *argv[]){
    Str a="Hello World！";
    Str b=a;
    str c;
    c = a+b; // c is "Hello World！" x2

    // print "Hello World！" x2
    for (int i = 0; i < c.size(); ++i){
        cout << c[i];
    }cout << endl;

    return 0;
}
//================================================================
