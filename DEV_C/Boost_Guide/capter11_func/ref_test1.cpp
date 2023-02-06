#include <string>                   //标准字符串类
#include <iostream>                 //标准输入输出
#include <vector>                   //标准向量容器
#include <set>                      //标准集合容器
#include <map>                      //标准映射容器
#include <algorithm>                //标准算法
#include <assert.h>
using namespace std;                //打开标准库的命名空间

#include <boost/ref.hpp>


int main(int argc, char const *argv[])
{
    int x = 10;
    boost::reference_wrapper<int> rw(x);    //包装int类型的引用
    assert(rw == x);                        //隐式转换为int

    (int &)rw = 100;                        //显示转换int&
    assert(x == 100);

    boost::reference_wrapper<int> rw2(rw);  //拷贝构造函数
    assert(rw2.get() == 100);

    string str;
    boost::reference_wrapper<string> rws(str);
    *rws.get_pointer() = "test reference_wrapper";
    cout << rws.get().size() << endl;


//  使用工厂函数
    double d = 2.71828;
    auto rwd = boost::cref(d);                          //包装double const
    cout << typeid(rwd).name() << endl;

    string str1;
    auto rws2 = boost::ref(str1);
    cout << typeid(rws2).name() << endl;
    *rws2.get_pointer() = "hello boost ref";
    cout << rws2.get() << endl;


    return 0;
}
