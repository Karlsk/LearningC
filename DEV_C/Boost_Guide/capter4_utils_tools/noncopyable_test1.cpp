#include <string>                   //标准字符串类
#include <iostream>                 //标准输入输出
#include <vector>                   //标准向量容器
#include <set>                      //标准集合容器
#include <map>                      //标准映射容器
#include <algorithm>                //标准算法
using namespace std;                //打开标准库的命名空间

#include <boost/noncopyable.hpp>
//无noncopyable工具的情况下
class do_not_copy_base
{
public:
    do_not_copy_base() {}
    ~do_not_copy_base() {}
private:
    do_not_copy_base(const do_not_copy_base &);             // 私有化拷贝构造函数，声明即可，不用实现

    do_not_copy_base& operator=(const do_not_copy_base&);   // 私有化拷贝赋值操作，声明即可，不用实现
};

//使用noncopyable，派生类
class do_not_copy : boost::noncopyable {};                  // 注意这里，使用默认的私有继承的允许的

int main(int argc, char const *argv[])
{
    do_not_copy d1;
    //do_not_copy d2(d1);                                   // 企图拷贝构造，编译错误

    do_not_copy d3;
    //d3 = d1;                                              // 企图拷贝赋值操作，编译错误

    return 0;
}
