#include <string>                   //标准字符串类
#include <iostream>                 //标准输入输出
#include <vector>                   //标准向量容器
#include <set>                      //标准集合容器
#include <map>                      //标准映射容器
#include <algorithm>                //标准算法
using namespace std;                //打开标准库的命名空间

#include <boost/pool/object_pool.hpp>
using namespace boost;

struct demo_class                   //一个示范类
{
public:
    int a,b,c;
    demo_class(int x = 1, int y = 2, int z = 3)
        :a(x),b(y),c(z) {}
    ~demo_class()
    {   cout << "release demo_class object_pool" << endl;   }
};

int main(int argc, char const *argv[])
{
    object_pool<demo_class> p1;         //对象内存池

    auto p = p1.malloc();               //分配一个原始内存块
    assert(p1.is_from(p));

    //p指向的内存块未被初始化
    assert(p->a != 1 && p->b != 2 && p->c != 3);

    p = p1.construct(7,8,9);
    assert(p->a == 7);

    object_pool<string> pls;            //定义一个分配string对象的内存池

    for(int i = 0; i < 10; ++i)
    {
        string *ps = pls.construct("hello object_pool");
        cout << *ps << endl;
    }

    return 0;
}                                       //离开作用域，所有内存池，以及内存池分配出去的内存都被真确释放，并正确析构对象
