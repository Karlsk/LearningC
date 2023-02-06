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

class self_shared:                                          //一个需要shared_ptr自我管理的类
    public boost::enable_shared_from_this<self_shared> 
{
public:
    explicit self_shared(int n) :x(n) {}
    int x;
    void print()
    {
        cout << "self_shared: " << x << endl;
    }
};

int main(int argc, char const *argv[])
{
    auto sp = boost::make_shared<self_shared>(313);
    sp->print();

    auto p = sp->shared_from_this();
    auto wp = sp->weak_from_this();
    assert(!wp.expired());
    p->x = 1000;
    cout << p.use_count() << endl;
    p->print();
    return 0;
}
