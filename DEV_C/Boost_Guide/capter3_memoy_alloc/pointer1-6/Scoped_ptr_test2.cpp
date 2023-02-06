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

struct posix_file                           //一个示范性质的文件类
{
    explicit posix_file(const char * file_name)      //构造函数，打开一个文件
    {   
        cout << "Open file: " << file_name << endl;
    }

    ~posix_file()                           //析构函数，关闭文件
    {
        cout << "Close file." << endl;
    }

};

int main(int argc, char const *argv[])
{
    //文件类的Scoped_ptr，将在离开作用域时自动析构，从而关闭文件，释放资源
    scoped_ptr<posix_file> fp (new posix_file("/tmp/a.txt"));

    scoped_ptr<int> p (new int);            //一个int指针的Scoped_ptr
    if(p)                                   //在bool语境中测试指针是否有效
    {
        *p = 100;                           //可以像普通指针一样使用解引用操作符*
        cout << *p << endl;
    }
    p.reset();                               //置空Scoped_ptr，仅掩饰

    assert(p == 0);
    assert (p == nullptr);
    if(!p)
    {
        cout << "Scoped_ptr == nullptr" << endl;
    }

    return 0;
}

