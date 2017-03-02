/*****************************************************************
Name : 
Date : 2017/03/02
By   : CharlotteHonG
Final: 2017/03/02
*****************************************************************/
#include <iostream>
#include <vector>
using namespace std;

class Arr {
public:
    Arr(int len=5):arr(len){
        for(unsigned i = 1; i < arr.size(); ++i) {
            arr[i]=i;
        }
    }
    void pri(){
        for(auto&& i : arr) {
            cout << i << ", ";
        }
    }
    void set(int idx,int num){
        arr[idx]=num;
    }
    int & at(int idx){
        return arr[idx];
    }
    int & operator[](size_t idx){
        return arr[idx];
    }
    void operator=(Arr rhs){
        for(unsigned i = 0; i < arr.size(); ++i) {
            arr[i]=rhs[i];
        }
    }
private:
    vector<int> arr;
};
/*==============================================================*/
int main(int argc, char const *argv[]){
    Arr a, b, c;
    a.pri();
    cout << endl;
    // 三個等價
    a.set(0, 7);
    a.at(0)=7;
    a[0]=7;
    // 印出
    for(unsigned i = 0; i < 5; ++i) {
        cout << a[i]<< ", ";
        // cout << a.operator[](i)<< endl;
    } cout << endl;
    b=a;
    // b.operator=(a);
    b.pri();
    return 0;
}
/*==============================================================*/