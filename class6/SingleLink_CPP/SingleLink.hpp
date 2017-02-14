/*****************************************************************
Name : 
Date : 2016/11/20
By   : CharlotteHonG
Final: 2017/02/14
*****************************************************************/
#ifndef SINGLELINK_HPP
#define SINGLELINK_HPP value

#include <iostream>
#include <iomanip>
#include <ctime>
using namespace std;

namespace sgl {
//----------------------------------------------------------------
// 結構
struct Node {
    void* data;
    Node* next; 
}; 
using Head = Node;
//----------------------------------------------------------------
// 初始化亂數種子
int rand_int(int low, int up);
// 取亂數(不包含up)
void rand_init();
// 動態整數
int* dint(int data);
//----------------------------------------------------------------
// 創建節點
Node* Node_create(int* data);
// 印出節點
void Node_pri(Node* n);
// 查找長度
size_t Node_len(Node* n);
//----------------------------------------------------------------
// 存取地址
Node* Node_at(Head* n, int idx);
// 插入資料
void Node_insert_data(Head* n, size_t idx, int* data);
// 移出節點
Node* Node_unlink(Head* n, size_t idx);
// 刪除節點
void Node_del(Head* n, size_t idx);
//----------------------------------------------------------------
// 找結尾
Node* Node_tail(Node* n);
// 從尾端加入
void Node_append(Node* n, int* data);
// 印出全部
void Node_pri_all(Node* n);
// 刪除全部
void Node_del_all(Node* n);
//----------------------------------------------------------------
// 插入節點
void Node_insert(Node* n, Node* n2);
// 交換
void Node_change(Head* n, size_t idx);
// 存取整數地址
int* Node_at_int(Node* n, int idx);
// 排序
void Node_sort(Node* n);
//----------------------------------------------------------------
} // sgl
#endif