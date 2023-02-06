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

struct demo_class
{
    int add(int a, int b)           //加法操作
    {   return a + b;   }
    int operator()(int x)           //重载operator()
    {   return x*x; }
};

int main(int argc, char const *argv[])
{
    boost::function<int (demo_class&, int,int)> func1;
    func1 = boost::bind(&demo_class::add,_1,_2,_3);

    demo_class sc;
    cout << func1(sc, 10, 20) << endl;

    boost::function<int (int ,int)> func2;
    func2 = boost::bind(&demo_class::add,&sc,_1,_2);
    cout << func2(10,20) << endl;
    return 0;
}
