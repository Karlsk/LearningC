#include <string>                   //标准字符串类
#include <iostream>                 //标准输入输出
#include <vector>                   //标准向量容器
#include <set>                      //标准集合容器
#include <map>                      //标准映射容器
#include <algorithm>                //标准算法
#include <assert.h>
using namespace std;                //打开标准库的命名空间

#include <boost/ref.hpp>

class big_class
{
private:
    int x;
public:
    big_class() : x(0) {}
    void print()
    {   cout << "big_class " << ++x << endl;    }
};

template<typename T>
void print(T t)
{   
    for(int i = 0; i < 2; ++i)
    {
        boost::unwrap_ref(t).print();       //解包装
    }
    
}

int main(int argc, char const *argv[])
{
    big_class c;
    auto rw = boost::ref(c);
    c.print();                              //输出1

    print(c);                               //拷贝传参数，输出2，3， 内部状态不改变
    print(rw);                              //引用传参数，输出2，3， 内部状态改变
    print(c);                               //拷贝传参数，输出4，5 
    c.print();                              //输出4

    return 0;
}
