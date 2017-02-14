/*****************************************************************
Name : 
Date : 2017/02/14
By   : CharlotteHonG
Final: 2017/02/14
*****************************************************************/
#include <iostream>
using namespace std;
// hpp 函式宣告
class SingleLink{
public:
    // 建構子
    SingleLink(int n, int n2)
    : num(n), num2(n2){}
public:
    // 方法
    void pri();
private:
    int num;
    int num2;
};
// cpp 函式定義
void SingleLink::pri(){
    cout << "num=" << this->num << endl;
    cout << "num=" << this->num2 << endl;
}
/*==============================================================*/
int main(int argc, char const *argv[]){
    SingleLink a(7, 8);
    a.pri();
    return 0;
}
/*==============================================================*/