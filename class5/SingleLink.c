/*****************************************************************
Name : 
Date : 2016/11/19
By   : CharlotteHonG
Final: 2016/11/19
*****************************************************************/
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "SingleLink.h"
// 初始化亂數種子
int rand_int(int low, int up){
    return (int)((rand() / (RAND_MAX+1.0)) * (up - low) + low);
}
// 取亂數(不包含up)
void rand_init(){
    srand((unsigned)time(NULL));rand();
}
// 動態整數
int* dint(int data){
    int* num = (int*)malloc(sizeof(int));
    *num = data;
    return num;
}
//----------------------------------------------------------------
// 創建節點
Node* Node_create(int* data){
    Node* n = (Node*)malloc(sizeof(Node));
    n->data = data;
    n->next = NULL;
    return n;
}
// 印出節點
void Node_pri(Node* n){
    printf("%d, ", *(int*)n->data);
}
// 查找長度
size_t Node_len(Node* n){
    size_t lenth = 0;
    while( n->next != NULL && lenth<=999){
        n=n->next;
        lenth++;
    }
    return lenth;
}
// 存取地址
Node* Node_at(Head* n, int idx){
    // 返還頭地址
    if(idx<0)
        return n;
    // 避開頭
    Node* temp=n->next;
    // 開始尋找
    for(unsigned i = 0; i < idx; ++i) {
        if (temp->next==NULL)
            return temp;
        temp=temp->next;
    }
    return temp;
}
// 插入資料
void Node_insert_data(Head* n, size_t idx, int* data){
    // 旗標(插入點的前一個)
    Node* flag=NULL;
    if (idx == 0)
        flag = n;
    else
        flag = Node_at(n, --idx);

    Node* temp = flag->next;
    flag->next = Node_create(data);
    flag->next->next=temp;
}
// 移出節點
Node* Node_unlink(Head* n, size_t idx){
    Node* temp = Node_at(n, idx);
    Node_at(n, idx-1)->next = Node_at(n, idx)->next;
    temp->next = NULL;
    return temp;
}
// 刪除節點
void Node_del(Head* n, size_t idx){
    if (Node_len(n)==0)
        return;
    // 旗標(被刪除者的前一個)
    Node* flag=NULL;
    // 長度為1時
    if (Node_len(n)==1)
        idx=0;
    // 設置旗標
    if (idx == 0)
        flag = n;
    else
        flag = Node_at(n, --idx);

    Node* targ = flag->next;
    // 如果是最後一個
    if (targ == NULL)
        flag = Node_at(n, Node_len(n)-1-1);
    flag->next = flag->next->next;
    free(targ);
}
//----------------------------------------------------------------
// 找結尾
Node* Node_tail(Node* n){
    size_t lenth = 0;
    while( n->next != NULL && lenth<=999){
        n=n->next;
        lenth++;
    }
    return n;
}
// 從尾端加入
void Node_append(Node* n, int* data){
    Node_tail(n)->next = Node_create(data);
}
// 印出全部
void Node_pri_all(Node* n){
    for (int i = 0; i < Node_len(n); ++i){
        Node_pri(Node_at(n, i));
    } 
    printf("[len = %I64u]\n", Node_len(n));
}
// 刪除全部
void Node_del_all(Node* n){
    size_t node_len=Node_len(n);
    for (unsigned i = 0; i < node_len; ++i){
        Node_del(n, 0);
    }
}
//----------------------------------------------------------------
// 插入節點
void Node_insert(Node* n, Node* n2){
    n2->next = n->next;
    n->next = n2;
}
// 與下一個交換
void Node_change(Head* n, size_t idx){
    if(idx > Node_len(n)-1)
        idx=Node_len(n)-1;
    Node* temp = Node_unlink(n, idx);
    Node_insert(Node_at(n, idx), temp);
}
// 獲得整數地址
int* Node_at_int(Node* n, int idx){
    return (int*)Node_at(n, idx)->data;
}
// 排序
void Node_sort(Node* n) {
    for (unsigned j = 0; j < Node_len(n) - 1; j++) {
        for (unsigned i = 0; i < Node_len(n) - 1 - j; i++) {
            // 如果下一個比較小
            if (*Node_at_int(n, i) > *Node_at_int(n, i+1)) {
                // 交換
                Node_change(n, i);
            }
        }
    }
}
//----------------------------------------------------------------