#include <string>                   //标准字符串类
#include <iostream>                 //标准输入输出
#include <vector>                   //标准向量容器
#include <set>                      //标准集合容器
#include <map>                      //标准映射容器
#include <algorithm>                //标准算法
#include <assert.h>
using namespace std;                //打开标准库的命名空间

#include <boost/signals2.hpp>
using namespace boost::signals2;

void slots1()
{   cout << "slots1 called" << endl;  }

void slotsl2()
{   cout << "slots2 called" << endl; }

int main(void)
{
    /*
    ** 指定插槽类型void（），其他模版参数使用默认值
    ** 然后就可以用connect()来链接插槽
    ** 最后调用operator() 来产生信号 
    */

    signal<void()> sig;             //一个信号对象

    sig.connect(&slots1);           //链接插槽1
    sig.connect(&slotsl2);          //链接插槽2

    sig();                          //调用operator(),产生

    return 0;
}