/*****************************************************************
Name : 
Date : 2017/02/15
By   : CharlotteHonG
Final: 2017/02/15
*****************************************************************/
#include "SingleLink.hpp"

namespace sgl {
//----------------------------------------------------------------
// 插入節點
void SinLink::insert(Node* n, Node* n2){
    n2->next = n->next;
    n->next = n2;
}
// 移出節點
SinLink::Node* SinLink::unlink(size_t idx){
    Node* temp = at(idx);
    at(idx-1)->next = at(idx)->next;
    temp->next = NULL;
    return temp;
}
// 與下一個交換
void SinLink::change(size_t idx){
    if(idx > len()-1)
        idx=len()-1;
    Node* temp = unlink(idx);
    insert(at(idx), temp);
}
// 獲得整數地址
int* SinLink::at_int(int idx){
    return (int*)at(idx)->data;
}
//----------------------------------------------------------------
// 排序
void SinLink::sort() {
    for (unsigned j = 0; j < len() - 1; j++) {
        for (unsigned i = 0; i < len() - 1 - j; i++) {
            // 如果下一個比較小
            if (*at_int(i) > *at_int(i+1)) {
                // 交換
                change(i);
            }
        }
    }
}
//----------------------------------------------------------------
} // sigl
