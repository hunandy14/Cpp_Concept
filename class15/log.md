## 2017/07/07
與hpp檔搭配cpp檔要把 include.hpp 放在宣告之類下，不然會出問題

```cpp
class Base{
public:
    Base(std::string s="ABC");
private:
    std::string name;
};
```

```cpp
#include <iostream>
#include <string>
#include "muti_file.hpp"

using namespace std;

Base::Base(string s): name(s){
    cout << "name=" << name << endl;
}
```

如果把他寫成

```cpp
#include "muti_file.hpp"
#include <iostream>
#include <string>
```

就會出問題
