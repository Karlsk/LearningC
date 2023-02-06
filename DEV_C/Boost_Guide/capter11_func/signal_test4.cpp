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

//合并器的形式
// template<typename T>
// class combiner                      //自定义合并器
// {
// public:
//     typedef T result_type;          //返回值类型定义
    
//     template<typename InputIterator>
//     result_type operator()(InputIterator,InputIterator) const;
// };

//合并器实例
template<typename T>
class combiner
{
private:
    T v;                                //计算返回值之和
public:
    typedef pair<T, T> result_type;

    combiner(T t = T()) : v(t) {}       //构造函数
    template<typename InputIterator>
    result_type operator()(InputIterator begin, InputIterator end) const
    {
        if(begin == end)
        {
            return result_type();
        }
        vector<T> vec(begin,end);       //使用容器，保存插槽调用结果
        T sum = accumulate(vec.begin(),vec.end(),v);
        T max = *max_element(vec.begin(),vec.end());

        return result_type(sum,max);

    }
};

int main(int argc, char const *argv[])
{
    signal<int(int),combiner<int>> sg1;
    
    sg1.connect(slots<10>());
    sg1.connect(slots<20>());
    sg1.connect(slots<30>(),at_front);

    auto x = sg1(2);
    cout << "sum: " << x.first <<  " max: " << x.second << endl;

     signal<int(int),combiner<int>> sg2(combiner<int>(100));
    
    sg2.connect(slots<10>());
    sg2.connect(slots<20>());
    sg2.connect(slots<30>(),at_front);

    auto y = sg2(2);
    cout << "sum: " << y.first <<  " max: " << y.second << endl;

    return 0;
}
