/*****************************************************************
Name :
Date : 2016/11/19
By   : CharlotteHonG
Final: 2017/02/14
*****************************************************************/
#include "SingleLink.hpp"
//----------------------------------------------------------------
// 單檔編譯引入
#include "SingleLink_core.cpp"
#include "SingleLink_basic.cpp"
#include "SingleLink_sort.cpp"
//----------------------------------------------------------------
namespace sgl {
// 建構子
SinLink::SinLink(): head(create(dint(-1))){
    this->rand_init();
}
// 解構子
SinLink::~SinLink(){
    delete [] this->head;
}
} // sigl
//----------------------------------------------------------------