/*操做成员函数*/
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

void call_back_func(int i)
{
    cout << "call_back_func:    ";
    cout << i * 2 << endl;
}

int main(int argc, char const *argv[])
{
    demo_class dc(10);
    dc.accept(call_back_func);
    dc.run();
    return 0;
}
