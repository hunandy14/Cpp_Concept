/*****************************************************************
Name : 
Date : 2017/03/16
By   : CharlotteHonG
Final: 2017/03/16
*****************************************************************/
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;
using uch=unsigned char;

// 匯入檔案
void read(string filename, vector<uch> & img_data) {
    // ##二進位模式開檔測試
    fstream img;
    img.open(filename, ios::in | ios::binary);
    // 如果開啟檔案失敗，fp為0；成功，fp為非0
    if(!img) {
        img.close();
        cout << "No file." << endl;
        exit(1);
    }
    else {
        // cout << "File ok." << endl;
    } img.close();
    // ##二進位模式讀檔
    // 取得總長
    img.open(filename, ios::in | ios::binary);
    img.seekg(0, ios::end);
    ifstream::pos_type filesize;
    filesize = img.tellg();
    img.seekg(0, ios::beg);
    // 讀取值
    img_data.vector::resize(filesize);
    img.read(reinterpret_cast<char*>(img_data.data()), filesize);
    img.close();
}
// 將記憶體資料匯出
void write(string filename, vector<uch> & img_data) {
    // 進位模式寫檔
    fstream img_file;
    img_file.open(filename, ios::out | ios::binary);
    img_file.write((char*)&img_data[0], img_data.size());
    img_file.close();
}
/*==============================================================*/
int main(int argc, char const *argv[]){
	vector<uch> img_data;
    read("IMG.raw", img_data);
    cout << (int)img_data[0] << endl;
    write("IMG_out.raw", img_data);
	return 0;
}
/*==============================================================*/