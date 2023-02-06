#include <string>                   //标准字符串类
#include <iostream>                 //标准输入输出
#include <vector>                   //标准向量容器
#include <set>                      //标准集合容器
#include <map>                      //标准映射容器
#include <algorithm>                //标准算法
using namespace std;                //打开标准库的命名空间

#include <boost/shared_ptr.hpp>
#include <boost/make_shared.hpp>

//if assert for 可以使用隐式转换
//其他情况必须使用显示转换，static_cast<bool>(ptr), ptr != nullptr, !!ptr
bool bool_test()
{
    auto p = boost::make_shared<int>(766);

    assert(p);                          //assert可以隐式修改

    if(p)                               //if判断可以隐式修改
    {
        cout << "explicit cast" << endl;
    }

    return static_cast<bool>(p);        //返回值必须显示转换
}