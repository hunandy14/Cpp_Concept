/*****************************************************************
Name : 
Date : 2017/07/25
By   : CharlotteHonG
Final: 2017/07/25
*****************************************************************/
#include <iostream>
using namespace std;

#pragma pack(2) // �վ���
struct S{
    uint16_t a; // 4
    uint32_t b; // 4
    uint16_t c; // 4
    uint16_t d;
    uint32_t e; // 4
};
#pragma pack() // ��_�w�]���
//================================================================
int main(int argc, char const *argv[]){
    cout << "sizeof(S)=" << sizeof(S) << endl;
    return 0;
}
//================================================================
