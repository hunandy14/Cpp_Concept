/*****************************************************************
Name : 
Date : 2016/11/19
By   : CharlotteHonG
Final: 2017/02/14
*****************************************************************/
#include <iostream>
#include "SingleLink.hpp"
#include "SingleLink.cpp"

using namespace std;
using namespace sgl;
#define arr_len 10

int main(int argc, char const *argv[]){
    // 創建陣列
    SinLink list;
    // 填值
    for (int i = arr_len-1; i > 0; --i)
        list.append(i);
    list.pri_all();
    // 位置1 插入77
    list.insert_data(1, 77);
    list.pri_all();
    // 位置1 刪除
    list.del(1);
    list.pri_all();
    // 隨機存取
    for (int i = 0; i < 10; ++i)
        cout << setw(3) << list.at_rand() << ",";
    cout << endl;
    // 排序
    list.sort();
    list.pri_all();
    return 0;
}
/*=======================================================*/