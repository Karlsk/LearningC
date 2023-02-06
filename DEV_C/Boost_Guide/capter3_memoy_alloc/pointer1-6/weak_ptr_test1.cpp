#include <string>                   //标准字符串类
#include <iostream>                 //标准输入输出
#include <vector>                   //标准向量容器
#include <set>                      //标准集合容器
#include <map>                      //标准映射容器
#include <algorithm>                //标准算法
using namespace std;                //打开标准库的命名空间

#include <boost/shared_ptr.hpp>
#include <boost/make_shared.hpp>
#include <boost/weak_ptr.hpp>

int main(int argc, char const *argv[])
{
    boost::shared_ptr<int> sp(new int(10));     //share_ptr
    assert(sp.use_count() == 1);

    boost::weak_ptr<int> wp(sp);
    assert(wp.use_count() == 1);                //weak_ptr不影响计数
    assert(!wp.empty());                        //weak_ptr此时为非空指针

    if (!wp.expired())                          //判断weak_ptr观察的对象是否失效
    {
        boost::shared_ptr<int> sp2 = wp.lock(); //获得一个shared_ptr
        *sp2 = 100;
        assert(wp.use_count() == 2);
        assert(sp.use_count() == 2);
    }                                           //退出作用域，sp2自动析构
    assert(wp.use_count() == 1);
    cout << *sp << endl;

    sp.reset();
    assert(wp.expired());                       //weak_ptr观察的对象sp已经失效

    assert(!wp.lock());                          //weak_ptr获得一个空指针
    
    return 0;
}
