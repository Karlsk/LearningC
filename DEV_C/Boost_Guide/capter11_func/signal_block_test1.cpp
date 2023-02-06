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

int main(void)
{
    signal<int(int)> sig;

    connection c1 = sig.connect(0,slots<10>());
    connection c2 = sig.connect(0,slots<20>());

    assert(sig.num_slots() == 2);               //有两个插槽链接
    sig(2);                                     //调用两个插槽

    cout << "begin blocking ..... "  << endl;
    {
        shared_connection_block block(c1);      //阻塞c1链接
        assert(sig.num_slots() == 2);           //仍然有两个链接
        assert(c1.blocked());
        sig(2);                                 //只有一个插槽被调用
    }                                           //离开作用域，阻塞自动被解除

    cout << "end blocking ......." << endl;
    assert(!c1.blocked());
    sig(2);
    
    return 0;
}