#include <string>                   //标准字符串类
#include <iostream>                 //标准输入输出
#include <vector>                   //标准向量容器
#include <set>                      //标准集合容器
#include <map>                      //标准映射容器
#include <algorithm>                //标准算法
using namespace std;                //打开标准库的命名空间

#include<boost/assign.hpp>
using namespace boost::assign;

int main(int argc, char const *argv[])
{
    vector<int> v = list_of(1).repeat(3,2)(3)(4)(5);

    cout << "initialization vector with repeat: ";
    for (auto i : v)
    {
        cout << i << ", ";
    }
    cout << endl;

    multiset<int> ms;
    insert(ms).repeat_fun(5,&rand).repeat(2,1),10;

    cout << "op set with repeat: ";
    for (auto i : ms)
    {
        cout << i << ", ";
    }
    cout << endl;

    deque<int> d;
    push_front(d).range(v.begin(),v.begin()+5);
    cout << "op deque with repeat: ";
    for (auto i : d)
    {
        cout << i << ", ";
    }
    cout << endl;
    return 0;
}
