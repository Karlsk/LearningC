#include <string>                   //标准字符串类
#include <iostream>                 //标准输入输出
#include <vector>                   //标准向量容器
#include <set>                      //标准集合容器
#include <map>                      //标准映射容器
#include <algorithm>                //标准算法
#include <math.h>
using namespace std;                //打开标准库的命名空间

#include <boost/optional.hpp>
using namespace boost;

optional<double> calc(int x)                //计算倒数
{
    return optional<double>(x != 0,1.0/x);  //条件构造函数
}

optional<double> sqrt_op(double x)          //计算平方根
{
    return optional<double>(x > 0, sqrt(x));//条件构造函数
}



int main(int argc, char const *argv[])
{
    optional<double> d = calc(10);
    if(d)
    {
        cout << *d << endl;
    }    

    d  = sqrt_op(-10);
    if(!d)
    {
        cout << "error: no result" << endl;
    }

    return 0;
}
