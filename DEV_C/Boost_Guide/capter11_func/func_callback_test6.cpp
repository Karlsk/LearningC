/*带状态的函数对象*/
#include <string>                   //标准字符串类
#include <iostream>                 //标准输入输出
#include <vector>                   //标准向量容器
#include <set>                      //标准集合容器
#include <map>                      //标准映射容器
#include <algorithm>                //标准算法
#include <assert.h>
using namespace std;                //打开标准库的命名空间

#include <boost/function.hpp>
#include <boost/bind.hpp>

class call_back_factory
{
public:
    void call_back_func1(int i)             //一个参数
    {   
        cout << "call_back_factory_func1: ";
        cout << i * 2 << endl; 
    }
    void call_back_func2(int a, int b)      //两个参数
    {
        cout << "call_back_factory_func2: ";
        cout << a * b * 2 << endl; 
    }
};

class demo_class
{
private:
    typedef boost::function<void(int)> func_t;  //function类型定义
    func_t func;                                //function对象
    int n;                                      //内部成员变量
public:
    demo_class(int i) : n(i) {};                //构造函数

    //模版函数
    template<typename CallBack>
    void accept(CallBack f)                     //存储回调函数
    {
        func = f;
    }

    void run()                                  //调用回调函数
    {
        func(n);
    }
};


int main(int argc, char const *argv[])
{
    demo_class dc(10);
    call_back_factory cbf;
    dc.accept(boost::bind(&call_back_factory::call_back_func1,cbf,_1));
    dc.run();                           //输出：call_back_factory_func1: 20
    dc.accept(boost::bind(&call_back_factory::call_back_func2,cbf,_1,5));
    dc.run();                           //输出：call_back_factory_func2: 100

    return 0;
}
