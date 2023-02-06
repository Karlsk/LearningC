# 内存管理
## smart_ptr库概述
### RAII机制
- RAII（资源获取及初始化）
- 对象是用申明的方式在栈上创建的（一个局部变量），RAII机制会正常工作，离开作用域时，会自动调用析构函数释放资源。
- 使用new创建的对象必须调用delete来释放资源，这是造成内存泄漏的主要原因

### 智能指针
```c
#include <boost/smart_ptr.hpp>
using namespace boost;
```
