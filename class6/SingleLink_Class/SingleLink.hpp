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
// 結構
class SinLink{
private:
    struct Node {
        void* data;
        Node* next; 
    }; using Head = Node;
public:
    SinLink();
    ~SinLink();
// 基本功能
private:
    // 取亂數(不包含up)
    int rand_int(int low, int up);
    // 初始化亂數種子
    void rand_init();
    // 動態整數
    int* dint(int data);
    // 創建節點
    Node* create(int* data);
    // 查找長度
    size_t len();
    // 存取地址
    Node* at(int idx);
    // 找結尾
    Node* tail();
    // 印出節點
    void pri(Node* n);
public:
    // 印出全部
    void pri_all();
    // 從尾端加入
    void append(int data);
    // 插入資料
    void insert_data(size_t idx, int data);
    // 隨機存取整數
    int& at_rand();
    // 刪除節點
    void del(size_t idx);
    // 刪除全部
    void del_all();
// 排序
private:
    // 插入節點
    void insert(Node* n, Node* n2);
    // 移出節點
    Node* unlink(size_t idx);
    // 交換
    void change(size_t idx);
    // 存取整數地址
    int* at_int(int idx);
public:
    // 排序
    void sort();
private:
    Head* const head;
};
} // sgl


#endif
