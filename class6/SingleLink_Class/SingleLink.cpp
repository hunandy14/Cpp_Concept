/*****************************************************************
Name :
Date : 2016/11/19
By   : CharlotteHonG
Final: 2017/02/14
*****************************************************************/
#include "SingleLink.hpp"
//----------------------------------------------------------------
namespace sgl {
SinLink::SinLink(){
    this->rand_init();
    this->head = Node_create(dint(-1));
}
//----------------------------------------------------------------
// 初始化亂數種子
int SinLink::rand_int(int low, int up){
    return (int)((rand() / (RAND_MAX+1.0)) * (up - low) + low);
}
// 取亂數(不包含up)
void SinLink::rand_init(){
    srand((unsigned)time(NULL));rand();
}
// 動態整數
int* SinLink::dint(int data){
    int* num = (int*)malloc(sizeof(int));
    *num = data;
    return num;
}
//----------------------------------------------------------------
// 創建節點
SinLink::Node* SinLink::Node_create(int* data){
    Node* n = new Node;
    n->data = data;
    n->next = nullptr;
    return n;
}
// 印出節點
void SinLink::Node_pri(Node* n){
    cout << setw(3) << *(int*)n->data << ",";
}
// 查找長度
size_t SinLink::Node_len(){
    size_t lenth = 0;
    Node* n = this->head;
    while( n->next != NULL && lenth<=999){
        n=n->next;
        lenth++;
    }
    return lenth;
}
//----------------------------------------------------------------
// 存取地址
SinLink::Node* SinLink::Node_at(int idx){
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
// 插入資料
void SinLink::Node_insert_data(size_t idx, int data){
    // 旗標(插入點的前一個)
    Node* flag=NULL;
    if (idx == 0)
        flag = this->head;
    else
        flag = Node_at(--idx);

    Node* temp = flag->next;
    flag->next = Node_create(dint(data));
    flag->next->next=temp;
}
// 刪除節點
void SinLink::Node_del(size_t idx){
    if (Node_len()==0)
        return;
    // 旗標(被刪除者的前一個)
    Node* flag=NULL;
    // 長度為1時
    if (Node_len()==1)
        idx=0;
    // 設置旗標
    if (idx == 0)
        flag = this->head;
    else
        flag = Node_at(--idx);

    Node* targ = flag->next;
    // 如果是最後一個
    if (targ == NULL)
        flag = Node_at(Node_len()-1-1);
    flag->next = flag->next->next;
    free(targ);
}
//----------------------------------------------------------------
// 找結尾
SinLink::Node* SinLink::Node_tail(){
    Node* n = this->head;
    size_t lenth = 0;
    while( n->next != NULL && lenth<=999){
        n=n->next;
        lenth++;
    }
    return n;
}
// 從尾端加入
void SinLink::Node_append(int data){
    Node_tail()->next = Node_create(dint(data));
}
// 印出全部
void SinLink::Node_pri_all(){
    for (unsigned i = 0; i < Node_len(); ++i){
        Node_pri(Node_at(i));
    }cout << endl;
}
// 刪除全部
void SinLink::Node_del_all(){
    size_t node_len=Node_len();
    for (unsigned i = 0; i < node_len; ++i){
        Node_del(0);
    }
}
//----------------------------------------------------------------
// 插入節點
void SinLink::Node_insert(Node* n, Node* n2){
    n2->next = n->next;
    n->next = n2;
}
// 移出節點
SinLink::Node* SinLink::Node_unlink(size_t idx){
    Node* temp = Node_at(idx);
    Node_at(idx-1)->next = Node_at(idx)->next;
    temp->next = NULL;
    return temp;
}
// 與下一個交換
void SinLink::Node_change(size_t idx){
    if(idx > Node_len()-1)
        idx=Node_len()-1;
    Node* temp = Node_unlink(idx);
    Node_insert(Node_at(idx), temp);
}
// 獲得整數地址
int* SinLink::Node_at_int(int idx){
    return (int*)Node_at(idx)->data;
}
// 排序
void SinLink::Node_sort() {
    for (unsigned j = 0; j < Node_len() - 1; j++) {
        for (unsigned i = 0; i < Node_len() - 1 - j; i++) {
            // 如果下一個比較小
            if (*Node_at_int(i) > *Node_at_int(i+1)) {
                // 交換
                Node_change(i);
            }
        }
    }
}
//----------------------------------------------------------------
} // sigl
//----------------------------------------------------------------