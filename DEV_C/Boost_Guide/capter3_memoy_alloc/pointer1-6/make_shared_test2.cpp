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
    typedef vector<boost::shared_ptr<int>> vs;      //一个持有shared_ptr的标准容器类型
    vs v(10);                                       //申明一个拥有10个shared_ptr的容器
                                                    //元素被初始化为nullptr
    int i = 0;
    for ( auto pos = v.begin(); pos != v.end(); ++pos)
    {
        (*pos) = boost::make_shared<int>(++i);      //使用工厂函数赋值
        cout << *(*pos) << ", ";
    }
    cout << endl;

    boost::shared_ptr<int> p = v[9];
    *p = 100;
    cout << "count: " << v[9].use_count() << " value: " << *(v[9]) << endl;
    p.reset();
    cout << "count: " << v[9].use_count() << " value: " << *(v[9]) << endl;

    vs vr(10);
    
    for (auto &ptr : vr)
    {
        ptr = boost::make_shared<int>(++i);
        cout << *ptr << ", ";
    }
    cout << endl;
    
    

    return 0;
}
