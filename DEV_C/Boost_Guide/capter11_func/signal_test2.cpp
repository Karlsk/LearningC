#include <string>                   //标准字符串类
#include <iostream>                 //标准输入输出
#include <vector>                   //标准向量容器
#include <set>                      //标准集合容器
#include <map>                      //标准映射容器
#include <algorithm>                //标准算法
#include <assert.h>
using namespace std;                //打开标准库的命名空间

#include <boost/signals2.hpp>
using namespace boost::signals2;

template<int N>
struct slots                        //模版类。可以生成一系列的插槽
{
    void operator()()
    {   cout << "slots " << N << " called" << endl; }
};

int main(int argc, char const *argv[])
{
    signal<void()> sg1;
    sg1.connect(slots<1>(),at_back);
    sg1.connect(slots<100>(),at_front);

    sg1.connect(5,slots<51>(),at_back);
    sg1.connect(5,slots<55>(),at_front);

    sg1.connect(3,slots<30>(),at_front);
    sg1.connect(3,slots<33>(),at_back);

    sg1.connect(10,slots<10>());

    sg1();




    return 0;
}
