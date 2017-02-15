/*****************************************************************
Name : 
Date : 2017/02/15
By   : CharlotteHonG
Final: 2017/02/15
*****************************************************************/
#include "SingleLink.hpp"

namespace sgl {
//----------------------------------------------------------------
// 取亂數(不包含up)
int SinLink::rand_int(int low, int up){
    return (int)((rand() / (RAND_MAX+1.0)) * (up - low) + low);
}
// 初始化亂數種子
void SinLink::rand_init(){
    srand((unsigned)time(NULL));
    rand();
}
// 動態整數
int* SinLink::dint(int data){
    int* num = (int*)malloc(sizeof(int));
    *num = data;
    return num;
}
// 創建節點
SinLink::Node* SinLink::create(int* data){
    Node* n = new Node;
    n->data = data;
    n->next = nullptr;
    return n;
}
// 查找長度
size_t SinLink::len(){
    size_t lenth = 0;
    Node* n = this->head;
    while( n->next != NULL && lenth<=999){
        n=n->next;
        lenth++;
    }
    return lenth;
}
// 存取地址
SinLink::Node* SinLink::at(int idx){
    // 返還頭地址
    if(idx<0)
        return this->head;
    // 避開頭
    Node* temp=this->head->next;
    // 開始尋找
    for(int i = 0; i < idx; ++i) {
        if (temp->next==NULL)
            return temp;
        temp=temp->next;
    }
    return temp;
}
// 找結尾
SinLink::Node* SinLink::tail(){
    Node* n = this->head;
    size_t lenth = 0;
    while( n->next != NULL && lenth<=999){
        n=n->next;
        lenth++;
    }
    return n;
}
// 印出節點
void SinLink::pri(Node* n){
    cout << setw(3) << *(int*)n->data << ",";
}
//----------------------------------------------------------------
} // sgl