/*****************************************************************
Name : 
Date : 2017/02/14
By   : CharlotteHonG
Final: 2017/02/14
*****************************************************************/
#include <iostream>
using namespace std;

// hpp
class SingleLink{
public:
    // 建構子
    SingleLink(int n)
    : num(n){}
public:
    // 方法
    void pri();
private:
    int num;
};
// cpp
void SingleLink::pri(){
    cout << "num=" << this->num << endl;
}
/*==============================================================*/
int main(int argc, char const *argv[]){
    SingleLink a(7);
    a.pri();
    return 0;
}
/*==============================================================*/