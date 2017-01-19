/*****************************************************************
Name : 
Date : 2017/01/19
By   : CharlotteHonG
Final: 2017/01/19
*****************************************************************/
#include <iostream>
using namespace std;
/*==============================================================*/
int main(int argc, char const *argv[]){
	int y=3, x=4;
	// 創建
	int** arr = new int*[y];
	for (int i = 0; i < y; ++i){
		arr[i] = new int[x]{};
	}
	// 釋放
	for (int i = 0; i < y; ++i){
		delete [] arr[i];	
	} delete [] arr;

	return 0;
}
/*==============================================================*/