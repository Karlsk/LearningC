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

template<int N>
bool operator==(const slots<N>& , const slots<N>&)
{
    return true;
}

int main(int argc, char const *argv[])
{
    signal<int(int)> sig;

    assert(sig.empty());                //刚开始没有链接任何插槽

    sig.connect(0,slots<10>());
    sig.connect(0,slots<20>());
    sig.connect(1,slots<30>());

    assert(sig.num_slots() == 3);       //目前有三个插槽

    sig.disconnect(0);                  //断开组号为0的插槽，共两个
    assert(sig.num_slots() == 1);

    sig.disconnect(slots<30>());        //断开一个特定插槽
    assert(sig.empty());

    return 0;
}


