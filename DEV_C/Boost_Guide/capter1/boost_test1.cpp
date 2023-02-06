#include <string>                   //标准字符串类
#include <iostream>                 //标准输入输出
#include <vector>                   //标准向量容器
#include <set>                      //标准集合容器
#include <map>                      //标准映射容器
#include <algorithm>                //标准算法
using namespace std;                //打开标准库的命名空间

#include <boost/version.hpp>
#include <boost/config.hpp>

int main(int argc, char const *argv[])
{
    cout << BOOST_VERSION << endl;          //Boost版本号
    cout << BOOST_LIB_VERSION << endl;      //Boost版本号
    cout << BOOST_PLATFORM << endl;         //操作系统
    cout << BOOST_COMPILER << endl;         //编译器
    cout << BOOST_STDLIB << endl;           //标准库
    return 0;
}
