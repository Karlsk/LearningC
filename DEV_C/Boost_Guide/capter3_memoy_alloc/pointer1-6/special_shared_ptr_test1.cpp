#include <string>                   //标准字符串类
#include <iostream>                 //标准输入输出
#include <vector>                   //标准向量容器
#include <set>                      //标准集合容器
#include <map>                      //标准映射容器
#include <algorithm>                //标准算法
using namespace std;                //打开标准库的命名空间
#include <boost/shared_ptr.hpp>
#include <boost/make_shared.hpp>

int main(int argc, char const *argv[])
{
    auto p1 = boost::make_shared<std::pair<int, int>>(0,1);

    boost::shared_ptr<int> p2(p1, &(p1->second));             //别名构造
    assert(p1.use_count() == 2 && p1.use_count() == p2.use_count());

    assert((void*)p1.get() != (void*)p2.get());             //指向的内容不同

    assert(&p1 -> second == p2.get());                      //指向的是另外的指针


    return 0;
}
