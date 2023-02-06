#include <string>                   //标准字符串类
#include <iostream>                 //标准输入输出
#include <vector>                   //标准向量容器
#include <set>                      //标准集合容器
#include <map>                      //标准映射容器
#include <algorithm>                //标准算法
using namespace std;                //打开标准库的命名空间

#include <boost/optional.hpp>
using namespace boost;

//make_optional工厂模式，不能使用<T&>
int main(int argc, char const *argv[])
{
    auto x = make_optional<int>(5);
    assert(*x == 5);

    auto y = make_optional<double>(*x > 10, 1.0);
    assert(!y);
    return 0;
}
