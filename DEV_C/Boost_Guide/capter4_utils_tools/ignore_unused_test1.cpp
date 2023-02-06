#include <string>                   //标准字符串类
#include <iostream>                 //标准输入输出
#include <vector>                   //标准向量容器
#include <set>                      //标准集合容器
#include <map>                      //标准映射容器
#include <algorithm>                //标准算法
using namespace std;                //打开标准库的命名空间

#include <boost/core/ignore_unused.hpp>

int func_warning(int x, int y)
{
    int i;
    return y;
}                                   //i和x都未使用，gcc会报警告

int func(int x, int y)
{
    int i;
    boost::ignore_unused(x,i);      //相当于(void)x;(void)y;

    return y;
}

void func2()
{
    typedef int result_type;                    //局部类型定义
    boost::ignore_unused<result_type>();        //忽略未使用的类型定义
}

int main(int argc, char const *argv[])
{
    return 0;
}
