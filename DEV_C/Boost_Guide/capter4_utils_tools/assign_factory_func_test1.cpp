#include <string>                   //标准字符串类
#include <iostream>                 //标准输入输出
#include <vector>                   //标准向量容器
#include <set>                      //标准集合容器
#include <map>                      //标准映射容器
#include <algorithm>                //标准算法
#include <forward_list>
using namespace std;                //打开标准库的命名空间
#include <boost/assign.hpp>
using namespace boost::assign;      //启用boost::assign库的功能

int main(int argc, char const *argv[])
{
    vector<int> v;
    push_back(v)(1)(2)(3)(4)(5);
    cout << "operator vector: ";
    for (auto i : v)
    {
        cout << i << ", ";
    }
    cout << endl;

    list<string> l;
    push_front(l)("c")("cpp")("lua")("swift");

    forward_list<string> fl;            //C++的单向链表容器
    push_front(fl)("matrix")("reload");

    set<double> s;
    insert(s)(3.14)(0.88)(0.618);

    map<int,string> m;
    insert(m)(1,"one")(2,"two");
    cout << "operator map:  ";
    for (auto i : m)
    {
        cout << i.first << " " << i.second << ", ";
    }
    cout << endl;

    
    return 0;
}
