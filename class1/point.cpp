/*****************************************************************
Name : 
Date : 2017/01/19
By   : CharlotteHonG
Final: 2017/01/19
*****************************************************************/
#include <iostream>
using namespace std;
using point = int*;
/*==============================================================*/
int main(int argc, char const *argv[]){
    // int i=5;
    // cout << &i << endl;

    // point p=&i;
    // cout << *p << endl;

    // point* p2=&p;
    // cout << **p2 << endl;
//----------------------------------------------------------------
    int len=10;
    // int arr0[len]{};
    // int* p = &arr[0];
    int* arr=new int[len]{1, 2};
    // * = de referrence
    // for (int i = 0; i < 10; ++i){
    //     cout << arr[i] << ",";
    // }
    delete [] arr;

    int* num=new int(10);
    delete arr;
//----------------------------------------------------------------





    return 0;
}
/*==============================================================*/