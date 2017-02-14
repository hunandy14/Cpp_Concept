## 小技巧

### 建構子
> 建立時執行

適合用來放初始化的操作。

### 解構子
> 結束時執行

適合用來delete函式

### 命名空間、指向

`SinLink::` 表示使用SinLink內的函式

程式中Node因為定義在 `SinLink` 裡面當你使用他時也必須加入  
如`SinLink::Node* SinLink::Node_create(int* data)`

