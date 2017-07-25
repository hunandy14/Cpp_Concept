/*****************************************************************
Name : BMP讀取檔頭
Date : 2017/07/19
By   : CharlotteHonG
Final: 2017/07/19
*****************************************************************/
#pragma once

#pragma pack(2) // 調整對齊
// 檔案檔頭 (BITMAPFILEHEADER)
struct BmpFileHeader{
    uint16_t bfTybe=0x4d42;
    uint32_t bfSize;
    uint16_t bfReserved1=0;
    uint16_t bfReserved2=0;
    uint32_t bfOffBits=54;
    // function
    friend std::ofstream& operator>>(
        std::ofstream& is, BmpFileHeader& obj);
    friend std::ifstream& operator<<(
        std::ifstream& os, const BmpFileHeader& obj);
};
inline std::ofstream& operator<<(
    std::ofstream& os, const BmpFileHeader& obj){
    os.write((char*)&obj, sizeof(obj));
    return os;
}
inline std::ifstream& operator>>(
    std::ifstream& is, BmpFileHeader& obj){
    is.read((char*)&obj, sizeof(obj));
    return is;
}
// 圖片資訊 (BITMAPINFOHEADER)
struct BmpInfoHeader{
    uint32_t biSize=40;
    uint32_t biWidth;
    uint32_t biHeight;
    uint16_t biPlanes=1; // 1=defeaul, 0=custom
    uint16_t biBitCount;
    uint32_t biCompression=0;
    uint32_t biXPelsPerMeter=0; // 72dpi=2835, 96dpi=3780
    uint32_t biYPelsPerMeter=0; // 120dpi=4724, 300dpi=11811
    uint32_t biClrUsed=0;
    uint32_t biClrImportant=0;
    // function
    friend std::ofstream& operator>>(
        std::ofstream& is, BmpInfoHeader& obj);
    friend std::ifstream& operator<<(
        std::ifstream& os, const BmpInfoHeader& obj);
};
inline std::ofstream& operator<<(
    std::ofstream& os, const BmpInfoHeader& obj){
    os.write((char*)&obj, sizeof(obj));
    return os;
}
inline std::ifstream& operator>>(
    std::ifstream& is, BmpInfoHeader& obj){
    is.read((char*)&obj, sizeof(obj));
    return is;
}
#pragma pack() // 恢復對齊為預設

