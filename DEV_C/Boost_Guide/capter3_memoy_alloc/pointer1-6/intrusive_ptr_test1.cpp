#include <string>                   //标准字符串类
#include <iostream>                 //标准输入输出
#include <vector>                   //标准向量容器
#include <set>                      //标准集合容器
#include <map>                      //标准映射容器
#include <algorithm>                //标准算法
using namespace std;                //打开标准库的命名空间

#include <boost/shared_ptr.hpp>
#include <boost/make_shared.hpp>
#include <boost/intrusive_ptr.hpp>

struct counted_data                 //自己实现引用计数
{
    int m_count = 0;                //引用计数
    //...
};

void intrusive_ptr_add_ref(counted_data *p)     //增加引用计数
{
    ++(p->m_count);
}

void intrusive_ptr_release(counted_data *p)     //减少引用计数
{
    if(--(p->m_count) == 0)
    {
        cout << "delete p" << endl;
        delete p;
    }
}

int main(int argc, char const *argv[])
{
    typedef boost::intrusive_ptr<counted_data> counted_ptr; //类型定义
    counted_ptr p(new counted_data);                        //创建智能指针
    assert(p);

    assert(p->m_count == 1);
    counted_ptr p2(p);
    assert(p->m_count == 2);

    counted_ptr wp(p.get(),false);                          //弱引用
    assert(p->m_count == 2);
    assert(wp->m_count == 2);

    p2.reset();
    assert(!p2);
    assert(p->m_count == 1);
    return 0;
}

