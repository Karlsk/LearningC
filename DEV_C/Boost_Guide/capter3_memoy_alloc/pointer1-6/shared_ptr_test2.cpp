#include <string>                   //标准字符串类
#include <iostream>                 //标准输入输出
#include <vector>                   //标准向量容器
#include <set>                      //标准集合容器
#include <map>                      //标准映射容器
#include <algorithm>                //标准算法
using namespace std;                //打开标准库的命名空间

#include <boost/shared_ptr.hpp>


int main(int argc, char const *argv[])
{
    typedef boost::shared_ptr<string> sp_t;     //shared_ptr类型定义

    map<sp_t,int> m;                            //标准映射容器
    
    sp_t sp(new string("one"));                 //一个shared_ptr对象
    m[sp] = 111;                                //关联数组用法

    cout << m[sp] << endl;

    return 0;
}
