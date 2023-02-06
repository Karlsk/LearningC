/*操做成员函数*/
#include <string>                   //标准字符串类
#include <iostream>                 //标准输入输出
#include <vector>                   //标准向量容器
#include <set>                      //标准集合容器
#include <map>                      //标准映射容器
#include <algorithm>                //标准算法
#include <assert.h>
using namespace std;                //打开标准库的命名空间

#include <boost/bind.hpp>

struct demo                          
{
    int f(int x, int y)
    {
        return (x+1) * y;
    }
};

int main(int argc, char const *argv[])
{
    demo a,&ra = a;                 //类的实例对象和引用
    demo *p = &a;                   //指针

    cout  << boost::bind(&demo::f,a,_1,20)(10) << endl;
    cout << boost::bind(&demo::f,ra,_2,_1)(10,20) << endl;
    cout << boost::bind(&demo::f,p,_1,_2)(10,20) << endl;

    return 0;
}
