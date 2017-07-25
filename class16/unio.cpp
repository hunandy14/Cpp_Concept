/*****************************************************************
Name : 
Date : 2017/07/25
By   : CharlotteHonG
Final: 2017/07/25
*****************************************************************/
#include <iostream>
using namespace std;

// byte4 型別
union byte4_t {
    uint32_t raw;
    struct Bit_slice {
        uint32_t a:8;
        uint32_t b:8;
        uint32_t c:8;
        uint32_t d:8;
    } bit;

    friend std::ostream& operator<<(
        std::ostream& os, byte4_t const& rhs);
};

inline std::ostream& operator<<(
        std::ostream& os, byte4_t const& rhs)   
    {
        os << static_cast<unsigned char>(rhs.bit.a);
        os << static_cast<unsigned char>(rhs.bit.b);
        os << static_cast<unsigned char>(rhs.bit.c);
        os << static_cast<unsigned char>(rhs.bit.d);
        return os;
    }
//================================================================
int main(int argc, char const *argv[]){
    byte4_t a;
    a.raw=100;


    return 0;
}
//================================================================
