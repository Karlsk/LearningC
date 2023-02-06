#include <string>                   //标准字符串类
#include <iostream>                 //标准输入输出
#include <vector>                   //标准向量容器
#include <set>                      //标准集合容器
#include <map>                      //标准映射容器
#include <algorithm>                //标准算法
using namespace std;                //打开标准库的命名空间

#include <boost/shared_ptr.hpp>
#include <boost/make_shared.hpp>

class abstract                      //接口类定义
{
public:
    virtual void f() = 0;
    virtual void g() = 0;

protected:
    //定义在protected，意味着只有他和他的子类，任何其他对象都无权调用delete来删除他
    virtual ~abstract() = default;  //注意这里
    
};

class impl : public abstract
{
public:
    impl() = default;
    virtual ~impl() = default;

public:
    virtual void f()
    {
        cout << "class impl f" << endl;
    }

    virtual void g()
    {
        cout << "class impl g" << endl;
    }
};

boost::shared_ptr<abstract> create()
{
    return boost::make_shared<impl>();
}

int main(int argc, char const *argv[])
{
    auto p = create();              //工厂函数创建对象
    p->f();                         //可以像普通指针一样使用
    p->g();                         //不必担心资源泄漏，shared_ptr会自动管理指针

    abstract *q = p.get();
    p->f();

    // delete q;                       //错误，virtual abstract::~abstract()’ is protected within this contex

    impl *d = (impl*)(p.get());
    //delete d;                           
    /*可以使用delete的方法删除ptr，应为impl的析构函数是public，但是会造成两次调用delete产生的非法指针错误，coredump*/


    return 0;
}
