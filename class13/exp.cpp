/*****************************************************************
Name : 
Date : 2017/06/13
By   : CharlotteHonG
Final: 2017/06/13
*****************************************************************/
#include <iostream>
using namespace std;


// 自訂型別
enum RGB {R, G, B};
// 自動安全型別
class RGB_t {
public:
    RGB_t(size_t rgb): rgb(RGB(rgb)) {
        if(rgb>2) {throw range_error("range only 0~2");}
    }
    inline operator RGB() {return rgb;}
private:
    RGB rgb;
};
// 使用自訂型別
void fun1(RGB_t rgb){}



// 自訂錯誤例外
class read_error : public std::runtime_error {
public:
    read_error(const std::string& str): std::runtime_error(str) {}
};
// 使用錯誤例外
void fun2(){
    throw read_error("No file.");
}



// 捕捉例外用法
void exp(){
    // try{
        // fun1(3);
        fun2();
    // }
    // catch (range_error e){
    //     cout << "err is = " << e.what() << '\n';
    // }
    // catch (runtime_error e){
    //     cout << "err is = " << e.what() << '\n';
    // }
    // catch (...){ // 捕捉任何型態例外
    //     cout << "any error" << endl;
    // }
}
//================================================================
int main(int argc, char const *argv[]){
    try {
        exp();
    }
    catch(read_error e) {
        cout << "例外" << e.what()  << endl;
    }
    
    return 0;
}
//================================================================
