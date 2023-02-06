#include <string>                   //标准字符串类
#include <iostream>                 //标准输入输出
#include <vector>                   //标准向量容器
#include <set>                      //标准集合容器
#include <map>                      //标准映射容器
#include <algorithm>                //标准算法
using namespace std;                //打开标准库的命名空间

#include <boost/shared_ptr.hpp>
#include <boost/make_shared.hpp>

int main(int argc, char const *argv[])
{
    auto sp  = boost::make_shared<string>("make_shared");       //创建string的共享指针
    auto spv = boost::make_shared<vector<int>>(10,2);           //创建vector的共享指针

    assert(spv->size() == 10);
    for (int i = 0; i < spv->size(); i++)
    {
       cout << (*spv)[i] << endl;
    }
    
    
    cout << spv->capacity() << endl;
    return 0;
}
