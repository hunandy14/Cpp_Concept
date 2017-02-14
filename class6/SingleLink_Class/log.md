## 問題
又踩一次雷了，因為修改了引入參數，導致批次修改時沒有發現這個問題，找了好久。
> 不是非必要而是，絕對不要修改引入參數。

```cpp
// 查找長度
size_t Node_len(Node* n){
    size_t lenth = 0;
    while( n->next != NULL && lenth<=999){
        n=n->next;
        lenth++;
    }
    return lenth;
}
```

批次統一修改成head

```cpp
// 查找長度
size_t Node_len(){
    size_t lenth = 0;
    while( head->next != NULL && lenth<=999){
        head=head->next;
        lenth++;
    }
    return lenth;
}
```

就出問題了，head是成員函數應該不能被更改的
阿應該在head加上const屬性，不知道初值陣列能不能做到
> 太好了可以呢。
