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
    int & operator[](size_t idx){
    	return arr[idx];
    }
private:
    vector<int> arr;
};
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