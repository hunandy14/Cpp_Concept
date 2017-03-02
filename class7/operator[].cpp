/*****************************************************************
Name : 
Date : 2017/03/02
By   : CharlotteHonG
Final: 2017/03/02
*****************************************************************/
#include <iostream>
#include <vector>
using namespace std;

class Arr
{
public:
    Arr();
    void pri(){
        for(auto&& i : arr) {
            cout << i << ", ";
        }
    }
    int & operator[](size_t idx);
    // Arr operator+(Arr& rhs);
private:
    vector<int> arr;
};

Arr::Arr(): arr(5){
    for(unsigned i = 1; i < arr.size(); ++i) {
        arr[i]=i;
    }
}
int & Arr::operator[](size_t idx){
    return arr[idx];
}
/*==============================================================*/
int main(int argc, char const *argv[]){
    Arr a, b;
    a.pri();
    cout << endl;
    a[0]=7;
    for(unsigned i = 0; i < 5; ++i) {
        cout << a[i]<< ", ";
        // cout << a.operator[](i)<< endl;
    }

    return 0;
}
/*==============================================================*/