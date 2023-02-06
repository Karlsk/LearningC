/*操作普通函数*/
#include <string>                   //标准字符串类
#include <iostream>                 //标准输入输出
#include <vector>                   //标准向量容器
#include <set>                      //标准集合容器
#include <map>                      //标准映射容器
#include <algorithm>                //标准算法
#include <assert.h>
using namespace std;                //打开标准库的命名空间

#include <boost/bind.hpp>

int f(int a, int b)                 //二元函数
{
    return a+b;
}

int g(int a, int b, int c)          //三元函数
{
    return a + b * c;
}

int main(int argc, char const *argv[])
{
    int x = 1, y = 2, z = 3;
    cout << boost::bind(f,1,2)() << endl;
    cout << boost::bind(g,_1,_2,_3)(1,2,3) << endl;

    boost::bind(f,_1,9)(x);                     //f(x,9),相当于bind2and(f,9)
    boost::bind(f,_1,_2)(x,y);                  //f(x,y)
    boost::bind(f,_2,_1)(x,y);                  //f(y,x)
    boost::bind(f,_1,_1)(x,y);                  //f(x,x),y参数被忽略

    boost::bind(g,_1,8,_2)(x,y);                //g(x,8,y)
    boost::bind(g,_3,_2,_2)(z,y,y);             //g(y,y,x),x参数忽略
    

    typedef decltype(&f) f_type;                //函数指针定义
    typedef decltype(&g) g_type;                //函数指针定义

    f_type fp = f;
    g_type gp = g;

    cout << boost::bind(fp,_1,9)(x) << endl;    //(*pf)(x,9)
    cout << boost::bind(gp,_3,_2,_2)(x,y,z) << endl;    //(*gp)(z,y,y)


    return 0;
}
