#include <string>                   //标准字符串类
#include <iostream>                 //标准输入输出
#include <vector>                   //标准向量容器
#include <set>                      //标准集合容器
#include <map>                      //标准映射容器
#include <algorithm>                //标准算法
using namespace std;                //打开标准库的命名空间

#include <boost/timer.hpp>

int main(int argc, char const *argv[])
{
    boost::timer t;

    cout << "max timespan: "                //可度量的最大时间
    << t.elapsed_max()/3600 << "h"<< endl;

    cout << "min timespan: "                //可度量的最小时间
    << t.elapsed_min()/3600 << "h"<< endl;

    cout << "Now time elapsed : "           //已经流逝的时间
    << t.elapsed() << "s"<< endl;

    return 0;
}

