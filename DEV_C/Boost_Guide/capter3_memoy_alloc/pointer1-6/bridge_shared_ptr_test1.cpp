#include <string>                   //标准字符串类
#include <iostream>                 //标准输入输出
#include <vector>                   //标准向量容器
#include <set>                      //标准集合容器
#include <map>                      //标准映射容器
#include <algorithm>                //标准算法
using namespace std;                //打开标准库的命名空间

#include <boost/shared_ptr.hpp>
#include <boost/make_shared.hpp>
#include "bridge_shared_ptr_test1.hpp"

class sample::impl          //内部类的实现
{
public:
    void print()
    {
        cout << "impl print" << endl;
    }
};

sample::sample():p(new impl){}

void sample::print()
{
    p -> print();
}

int main(int argc, char const *argv[])
{
    sample s;
    s.print();
    return 0;
}

