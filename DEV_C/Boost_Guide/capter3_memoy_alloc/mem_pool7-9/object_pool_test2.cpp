#include <string>                   //标准字符串类
#include <iostream>                 //标准输入输出
#include <vector>                   //标准向量容器
#include <set>                      //标准集合容器
#include <map>                      //标准映射容器
#include <algorithm>                //标准算法
using namespace std;                //打开标准库的命名空间

#include <boost/pool/object_pool.hpp>
using namespace boost;

template<typename P, typename ... Args>     //可变参数模版
inline typename P::element_type* construct(P &p, Args&& ... args)
{
    typename P::element_type* mem = p.malloc();

    assert(mem != 0);
    new (mem) typename P::element_type(std::forward<Args>(args)...);    //完美转发

    return mem;
}


struct demo_class                   //一个示范类
{
public:
    demo_class(int, int, int, int,int)
    {   cout << "demo class new" << endl;   }
    ~demo_class()
    {   cout << "release demo_class object_pool" << endl;   }
};

int main(int argc, char const *argv[])
{
    object_pool<demo_class> p1;
    auto d = construct(p1,1,2,3,5,10);
    return 0;
}                                       //离开作用域，所有内存池，以及内存池分配出去的内存都被真确释放，并正确析构对象
