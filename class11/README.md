## 1. 依照指定的介面完成程序
資料結構為 char* 不可更動  

> 注意：資料成員已修改為private屬性

正確結果  
![](https://github.com/hunandy14/Cpp_Concept/blob/master/class11/Str.png)

## 2. 完成圖片的放大縮小
開圖軟體：http://www.irfanview.com/
要開raw檔兩個都要抓下來安裝(irfanview與plugins)


假設一張圖原本的像素是

```t
1 2
3 4
```

放大兩倍

```t
1 1 2 2
1 1 2 2
3 3 4 4
3 3 4 4
```

縮小2倍則還原(不需處理細節丟失)
