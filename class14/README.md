## 作業
給一段代碼不可修改，補上缺失的定義部分

```cpp
class Int_A {
public:
    Int_t();
};
class Int_B {
public:
    Int_t();
};

int main(int argc, char const *argv[]){
    Int_A a(1), b(2);
    cout << a+b << endl;
    Int_B c(3), d(4);
    cout << c+d << endl;
    return 0;
}
```


```cpp

class Base {
public:
    Base();
};

void fun(Base* p) {
    p->fun();
}

int main(int argc, char const *argv[]){
    fun(new A); // print A
    fun(new B); // print B
    return 0;
}
```
