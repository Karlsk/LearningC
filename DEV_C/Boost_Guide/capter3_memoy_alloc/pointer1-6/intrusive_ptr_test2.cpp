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
#include <boost/smart_ptr/intrusive_ref_counter.hpp>

struct counted_data               //自己实现引用计数
    : public boost::intrusive_ref_counter<counted_data>
{
};


int main(int argc, char const *argv[])
{
    typedef boost::intrusive_ptr<counted_data> counted_ptr;

    counted_ptr p1(new counted_data);
    assert(p1);
    assert(p1->use_count() == 1);

    counted_ptr p2(p1);
    assert(p1->use_count() == 2);

    counted_ptr wp(p1.get(),false);
    assert(p1->use_count() == 2);
    assert(wp->use_count() == 2);

    p2.reset();
    assert(p1->use_count() == 1);


    return 0;
}

