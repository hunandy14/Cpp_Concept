/*****************************************************************
Name :
Date : 2016/11/19
By   : CharlotteHonG
Final: 2017/02/14
*****************************************************************/
#include "SingleLink.hpp"
//----------------------------------------------------------------
namespace sgl {
// 建構子
SinLink::SinLink(): head(create(dint(-1))){
    this->rand_init();
}
// 解構子
SinLink::~SinLink(){
    this->del_all();
}
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
// 印出全部
void SinLink::pri_all(){
    for (unsigned i = 0; i < len(); ++i)
        pri(at(i));
    cout << endl;
}
// 從尾端加入
void SinLink::append(int data){
    tail()->next = create(dint(data));
}
// 插入資料
void SinLink::insert_data(size_t idx, int data){
    // 旗標(插入點的前一個)
    Node* flag=NULL;
    if (idx == 0)
        flag = this->head;
    else
        flag = at(--idx);

    Node* temp = flag->next;
    flag->next = create(dint(data));
    flag->next->next=temp;
}
// 隨機存取整數
int& SinLink::at_rand(){
    int rand = rand_int(0, len());
    int& num = *(int*)at(rand)->data;
    return num;
}
// 刪除節點
void SinLink::del(size_t idx){
    if (len()==0)
        return;
    // 旗標(被刪除者的前一個)
    Node* flag=NULL;
    // 長度為1時
    if (len()==1)
        idx=0;
    // 設置旗標
    if (idx == 0)
        flag = this->head;
    else
        flag = at(--idx);

    Node* targ = flag->next;
    // 如果是最後一個
    if (targ == NULL)
        flag = at(len()-1-1);
    flag->next = flag->next->next;
    free(targ);
}
// 刪除全部
void SinLink::del_all(){
    for (unsigned i = 0; i < len(); ++i)
        del(0);
}
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
//----------------------------------------------------------------