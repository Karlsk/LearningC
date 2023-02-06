#include <string>                   //标准字符串类
#include <iostream>                 //标准输入输出
#include <vector>                   //标准向量容器
#include <set>                      //标准集合容器
#include <map>                      //标准映射容器
#include <algorithm>                //标准算法
using namespace std;                //打开标准库的命名空间

#include <boost/lexical_cast.hpp>
using namespace boost;

template<typename T>
bool num_vaild(const char* str)
{
    T tmp;
    return conversion::try_lexical_convert(str,tmp);    //尝试转换数字
}

int main(int argc, char const *argv[])
{
    int x;
    assert(!conversion::try_lexical_convert("0x100",x));    //不需要捕获异常，返回bool
    assert(conversion::try_lexical_convert("100",x));
    //检查字面量的合法性
    assert(num_vaild<int>("1234"));
    assert(!num_vaild<int>("3.14"));
    assert(num_vaild<double>("1.234"));

    return 0;
}
