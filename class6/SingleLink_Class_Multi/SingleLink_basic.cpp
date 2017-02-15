/*****************************************************************
Name : 
Date : 2017/02/15
By   : CharlotteHonG
Final: 2017/02/15
*****************************************************************/
namespace sgl {
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
} // sgl