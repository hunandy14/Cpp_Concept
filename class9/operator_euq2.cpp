/*****************************************************************
Name : 
Date : 2017/03/18
By   : CharlotteHonG
Final: 2017/03/18
*****************************************************************/
// 重載賦值符號
List & List::operator=(const List & rhs){
    // 相同則離開
    if(this == &rhs)
        return (*this);
    // 清除原始資源
    this->~List();
    // 重建資源
    this->list = new int[len];
    this->len = rhs.len;
    // 複製
    for(unsigned i = 0; i < this->len; ++i)
        (*this).list[i] = rhs.list[i];
    return (*this);
}