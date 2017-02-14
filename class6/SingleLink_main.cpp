/*****************************************************************
Name : 
Date : 2016/11/19
By   : CharlotteHonG
Final: 2016/11/19
*****************************************************************/
#include <stdlib.h>
#include <stdio.h>
#include "SingleLink.hpp"
#include "SingleLink.cpp"
#define arr_len 10
int main(int argc, char const *argv[]){
    rand_init();
    // 創建陣列
    Node* list = create(dint(-1));
    // 填值
    for (int i = arr_len-1; i > 0; --i)
        append(list, dint(i));
    pri_all(list);
    // 位置1 插入77
    insert_data(list, 1, dint(77));
    pri_all(list);
    // 位置1 刪除
    del(list, 1);
    pri_all(list);
    // 隨機存取
    for (int i = 0; i < 10; ++i){
        int rand = rand_int(0, arr_len);
        pri(at(list, rand));
    }
    printf("\n");
    // sort(list);


    // 刪除全部
    del_all(list);
    pri_all(list);
    // 釋放
    free(list);
    return 0;
}
/*=======================================================*/