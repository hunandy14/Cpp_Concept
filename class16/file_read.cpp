/*****************************************************************
Name : 
Date : 2017/07/18
By   : CharlotteHonG
Final: 2017/07/18
*****************************************************************/
#include <iostream>
#include <fstream>
#include "file_read.hpp"
using namespace std;
//================================================================
int main(int argc, char const *argv[]){
    BmpFileHeader bf;
    BmpInfoHeader bi;
    string imgName ="in.bmp";
    string imgName2 ="out.bmp";
    // 讀取圖片
    ifstream input;
    input.open(imgName, ios::binary);
    input.exceptions(ifstream::failbit|ifstream::badbit);
    input >> bf >> bi;
    size_t filesize = bf.bfSize;
    cout << "filesize = " << filesize << endl;
    // 寫入圖片
    ofstream output;
    output.open(imgName2, ios::binary);
    output.exceptions(ifstream::failbit|ifstream::badbit);
    bf.bfSize = filesize;
    output << bf << bi;
    return 0;
}
//================================================================
