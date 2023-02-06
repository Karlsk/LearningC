/* 测试 Scoped_ptr的用法*/
#include <string>                   //标准字符串类
#include <iostream>                 //标准输入输出
#include <vector>                   //标准向量容器
#include <set>                      //标准集合容器
#include <map>                      //标准映射容器
#include <algorithm>                //标准算法
using namespace std;                //打开标准库的命名空间

#include <iostream>
#include <boost/scoped_ptr.hpp>

using namespace boost;

int main(int argc, char const *argv[])
{
    scoped_ptr<string> sp (new string("text"));
    
    assert(sp);                     //使用显示bool转型
    assert (sp != nullptr);         //空指针比较操作

    cout << *sp << endl;            //operator*取字符串的内容
    cout << sp->size() << endl;     //operator->取字符串的长度

    // scoped_ptr<string> sp2 = sp;    //错误，scoped_ptr不能拷贝构造函数

    return 0;
}
