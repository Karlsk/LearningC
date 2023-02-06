#include <string>                   //标准字符串类
#include <iostream>                 //标准输入输出
#include <vector>                   //标准向量容器
#include <set>                      //标准集合容器
#include <map>                      //标准映射容器
#include <algorithm>                //标准算法
using namespace std;                //打开标准库的命名空间

#include <boost/noncopyable.hpp>

struct square 
{
    typedef void result_type;
    void operator()(int &x)
    {   x = x*x; }
};

int main(int argc, char const *argv[])
{
    vector<int> v = {1,2,3,4,5};
    for_each(v.begin(),v.end(),square());
    cout << "initialization vector: ";
    for (auto i : v)
    {
        cout << i << ", ";
    }
    cout << endl;
    return 0;
}


