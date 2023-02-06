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
    int operator()(int x)
    {   
        cout << "slots " << N << " called" << endl; 
        return x * N;
    }
};

int main(int argc, char const *argv[])
{
    signal<int(int)> sg1;
    
    sg1.connect(slots<10>());
    sg1.connect(slots<20>());
    sg1.connect(slots<50>());

    cout << *sg1(2) << endl;





    return 0;
}
