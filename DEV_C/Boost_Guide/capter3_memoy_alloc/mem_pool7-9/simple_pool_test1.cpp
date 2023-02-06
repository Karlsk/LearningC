#include <string>                   //标准字符串类
#include <iostream>                 //标准输入输出
#include <vector>                   //标准向量容器
#include <set>                      //标准集合容器
#include <map>                      //标准映射容器
#include <algorithm>                //标准算法
using namespace std;                //打开标准库的命名空间

#include <boost/pool/pool.hpp>
using namespace boost;

int main(int argc, char const *argv[])
{
    pool<> p1(sizeof(int));                     //一个可分配int的内存池

    int *p = static_cast<int*>(p1.malloc());    //必须把void*转换成需要的类型
    assert(p1.is_from(p));                      //测试分配的内存块p是否属于内存池p1

    p1.free(p);                                 //释放内存池分配的内存
    for (int i = 0; i < 100; i++)
    {
        p1.ordered_malloc(10);                  //连续分配10块内存
    }
    

    return 0;       
}                                               //内存池析构，所有分配的内存都被释放
