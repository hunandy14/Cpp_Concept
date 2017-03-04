## 20170304
```cpp
// 重載+=符號
Arr & Arr::operator+=(Arr const &rhs){
    for(unsigned i = 0; i < arr.size(); ++i)
        (*this)[i] += rhs[i];
    return (*this);
}
// 重載+符號(全域函式)
Arr operator+(Arr const &lhs, Arr const &rhs){
    return Arr(lhs += rhs);
}
```

抱錯：

```t
error: passing 'const Arr' as 'this' argument discards qualifiers [-fpermissive]
```

因為讓 `lhs` 去呼叫 `+=` 函式
然後 `lhs` 是帶 `const` 屬性
找不到 `const 版本` 的 `+=` 函式



```cpp
// 重載+符號(全域函式)
Arr operator+(Arr const &lhs, Arr const &rhs){
    return Arr(lhs) += rhs;
}
```

避開讓 `lhs` 去呼叫，先複製一份新的，再用新的在呼叫。


