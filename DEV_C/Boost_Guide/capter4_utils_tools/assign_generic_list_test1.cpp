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
    vector<int> v = list_of(1)(2)(3)(4)(5);
    cout << "initialization vector: ";
    for (auto i : v)
    {
        cout << i << ", ";
    }
    cout << endl;

    deque<string> ds = (list_of("power")("bomb"),"phazon","suit");

    set<int> s = (list_of(10),20,30,40,50);
    
    map<int, string> m = list_of(make_pair(1,"one"))(make_pair(2,"two"));
    cout << "initialization map:  ";
    for (auto i : m)
    {
        cout << i.first << " " << i.second << ", ";
    }
    cout << endl;

    //使用map_list_of改进对map的初始化操作
    map<int, int> m1 = map_list_of(1,2)(2,3)(3,4);

    map<int, string> m2 = map_list_of(1,"onr")(2,"two");
    cout << "initialization map use map_list_of:  ";
    for (auto i : m)
    {
        cout << i.first << " " << i.second << ", ";
    }
    cout << endl;

    return 0;
}
