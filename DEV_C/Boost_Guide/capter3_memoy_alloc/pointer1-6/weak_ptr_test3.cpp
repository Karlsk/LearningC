/*针对shared_ptr的循环引用，使用weak_ptr解决计数问题*/
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
#include <boost/enable_shared_from_this.hpp>


class node                              //使用shared_ptr循环引用导致count计数失效
{
public:
    ~node()                             //析构函数输出信息
    {   cout << "deleted shared_ptr link" << endl;  }
    typedef boost::shared_ptr<node> ptr_type;
    ptr_type next;
};

//使用weak_ptr形成循环引用
class node2
{
public:
    ~node2()                             //析构函数输出信息
    {   cout << "deleted weak_ptr link" << endl;  }
    typedef boost::weak_ptr<node2> ptr_weak;
    ptr_weak next;
};

int main(int argc, char const *argv[])
{
    auto p1 = boost::make_shared<node>();       //两个节点对象
    auto p2 = boost::make_shared<node>();

    p1->next = p2;                              //形成循环链表
    p2->next = p1;

    assert(p1.use_count() == 2);                //每个shared_ptr的引用计数都为2
    assert(p2.use_count() == 2);

    auto w1 = boost::make_shared<node2>();      //两个节点对象
    auto w2 = boost::make_shared<node2>();

    w1->next = w2;                              //形成循环链表
    w2->next = w1;

    assert(w1.use_count() == 1);                //每个shared_ptr的引用计数都为1
    assert(w2.use_count() == 1);

    if(!w1->next.expired())                     //检查“弱”引用是否有效
    {
        auto p3 = w1->next.lock();              //调用lock获得“强“引用
    }

    return 0;
}                                               //使用shared_ptr的，退出作用域时无法正确析构
                                                //使用weak_ptr的，退出作用域时正确析构shared_ptr
