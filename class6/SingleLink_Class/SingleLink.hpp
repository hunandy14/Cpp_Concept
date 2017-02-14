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
class SinLink{
public:
    struct Node {
        void* data;
        Node* next; 
    }; using Head = Node;
public:
    SinLink();
public:
    // 初始化亂數種子
    int rand_int(int low, int up);
    // 取亂數(不包含up)
    void rand_init();
    // 動態整數
    int* dint(int data);
    // 創建節點
    Node* Node_create(int* data);
public:
    // 印出節點
    void Node_pri(Node* n);
    // 查找長度
    size_t Node_len();
public:
    // 存取地址
    Node* Node_at(int idx);
    // 插入資料
    void Node_insert_data(size_t idx, int data);
    // 移出節點
    Node* Node_unlink(size_t idx);
    // 刪除節點
    void Node_del(size_t idx);
public:
    // 找結尾
    Node* Node_tail();
    // 從尾端加入
    void Node_append(int data);
    // 印出全部
    void Node_pri_all();
    // 刪除全部
    void Node_del_all();
public:
    // 插入節點
    void Node_insert(Node* n, Node* n2);
    // 交換
    void Node_change(size_t idx);
    // 存取整數地址
    int* Node_at_int(int idx);
    // 排序
    void Node_sort();
public:
    Head* head;
};



} // sgl
#endif