#include <string>                   //标准字符串类
#include <iostream>                 //标准输入输出
#include <vector>                   //标准向量容器
#include <set>                      //标准集合容器
#include <map>                      //标准映射容器
#include <algorithm>                //标准算法
using namespace std;                //打开标准库的命名空间

#include <boost/thread.hpp>
#include <boost/thread/thread.hpp>
#include <boost/thread/thread_pool.hpp>
#include <boost/pool/singleton_pool.hpp>


struct pool_tag                          //仅仅用于标记的空类
{
    pool_tag()
    {   cout << "new pool tag" << endl; }
    ~pool_tag()
    {   cout << "delete pool tag" << endl; }
};
typedef boost::singleton_pool<pool_tag, sizeof(int)> sql; //内存池定义

int main(int argc, char const *argv[])
{
    int *p = (int*)sql::malloc();
    assert(sql::is_from(p));

    sql::release_memory();
    cout << "release mem is unused" << endl;

    return 0;
}
