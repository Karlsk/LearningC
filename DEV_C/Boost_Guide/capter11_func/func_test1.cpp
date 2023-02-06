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

int f(int a, int b)
{
    return a + b;
}

int main(int argc, char const *argv[])
{
    boost::function<int (int,int)> func;        //无参数构造一个function对象
    assert(!func);                              //此时func不持有任何对象
    assert(func.empty());

    func = f;                                   //func 存储函数f
    assert(func.contains(&f));                  //验证已经存储函数f
    
    if(func)                                    //function可以转换成bool类型
    {
        cout << func(10,20) << endl;
    }

    func = 0;
    assert(func.empty());

    return 0;
}
