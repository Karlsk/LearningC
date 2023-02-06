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

template<typename T>
struct summary
{
    typedef void result_type;
    T sum;

    summary(T v = T()) : sum(v) {}
    void operator()(T const &x)
    {   sum += x;   }

};

int main(int argc, char const *argv[])
{
    vector<int> v = {1,3,5,7,9};

    summary<int> s;
    boost::function<void (int const&)> func(boost::ref(s));

    for_each(v.begin(), v.end(),func);
    cout << s.sum << endl;

    return 0;
}
