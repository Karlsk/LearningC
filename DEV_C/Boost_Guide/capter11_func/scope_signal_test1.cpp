#include <string>                   //标准字符串类
#include <iostream>                 //标准输入输出
#include <vector>                   //标准向量容器
#include <set>                      //标准集合容器
#include <map>                      //标准映射容器
#include <algorithm>                //标准算法
#include <assert.h>
#include <numeric>
using namespace std;                //打开标准库的命名空间

#include <boost/signals2.hpp>
using namespace boost::signals2;

template<int N>
struct slots                        //模版类。可以生成一系列的插槽
{
    int operator()(int x)
    {   
        cout << "slots " << N << " called" << endl; 
        return x * N;
    }
    
};


int main(int argc, char const *argv[])
{
    signal<int(int)> sig;

    sig.connect(0,slots<10>());
    assert(sig.num_slots() == 1);
    {
        scoped_connection sc = sig.connect(0,slots<20>());
        assert(sig.num_slots() == 2);
    }                               //离开局部作用域，临时链接自动断开
    assert(sig.num_slots() == 1);
    
    return 0;
}
