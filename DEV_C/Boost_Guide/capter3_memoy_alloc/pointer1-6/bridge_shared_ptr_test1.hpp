#include <string>                   //标准字符串类
#include <iostream>                 //标准输入输出
#include <vector>                   //标准向量容器
#include <set>                      //标准集合容器
#include <map>                      //标准映射容器
#include <algorithm>                //标准算法
using namespace std;                //打开标准库的命名空间

#include <boost/shared_ptr.hpp>
#include <boost/make_shared.hpp>

class sample
{
private:
    class impl;                     //不完整的内部类声明
    boost::shared_ptr<impl> p;      //share_ptr成员变量

public:
    sample();                       //构造函数
    void print();                   //提供给外界的接口
};

