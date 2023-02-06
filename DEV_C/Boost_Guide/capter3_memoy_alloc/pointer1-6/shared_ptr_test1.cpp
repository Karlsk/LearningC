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
    boost::shared_ptr<int> spi(new int);            //一个int的shared_ptr
    assert(spi);                                    //在bool语境中转换成bool值
    *spi = 253;                                     //使用解引用操作符*
    cout << *spi << endl;

    boost::shared_ptr<string> sps(new string("smart"));
    assert(sps->size() == 5);

    boost::shared_ptr<int> dont_do_this(new int[10]);   //危险，不能真确释放内存
    return 0;
}
