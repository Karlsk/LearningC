#include <string>                   //标准字符串类
#include <iostream>                 //标准输入输出
#include <vector>                   //标准向量容器
#include <set>                      //标准集合容器
#include <map>                      //标准映射容器
#include <algorithm>                //标准算法
using namespace std;                //打开标准库的命名空间

#include <boost/shared_ptr.hpp>

class shared                                    //一个拥有shared_ptr的类
{
private:
    boost::shared_ptr<int> p;                   //shared_ptr成员变量
public:
    explicit shared(boost::shared_ptr<int> p_)  //构造函数初始化shared_ptr
        : p(p_){}
    
    void print()                                //输出shared_ptr的引用计数和指向的值
    {
        cout << "count: " << p.use_count()
            << " value: " << *p << endl;
    }

};

void print_func(boost::shared_ptr<int> p)       //使用shared_ptr作为函数的参数,使用的是shared_ptr的拷贝，所以use_count() +1
{
    cout << "count: " << p.use_count()
            << " value: " << *p << endl;
}

int main(int argc, char const *argv[])
{
    boost::shared_ptr<int> p (new int(10));     //shared_ptr持有整数指针

    shared sp1(p), sp2(p);                      //构造两个自定义类

    sp1.print();
    sp2.print();

    *p = 20;                                    //修改shared_ptr所指向的值
    print_func(p);

    sp1.print();
    return 0;
}
