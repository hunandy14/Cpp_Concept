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
    rand_init();
    // 創建陣列
    Head* list = Node_create(dint(-1));
    // 填值
    for (int i = arr_len-1; i > 0; --i)
        Node_append(list, dint(i));
    Node_pri_all(list);
    // 位置1 插入77
    Node_insert_data(list, 1, dint(77));
    Node_pri_all(list);
    // 位置1 刪除
    Node_del(list, 1);
    Node_pri_all(list);
    // 隨機存取
    for (int i = 0; i < 10; ++i){
        int rand = rand_int(0, arr_len);
        Node_pri(Node_at(list, rand));
    }
    printf("\n");
    // 排序
    Node_sort(list);
    Node_pri_all(list);
    // 刪除全部
    Node_del_all(list);
    Node_pri_all(list);
    // 釋放
    free(list);
    return 0;
}
/*=======================================================*/