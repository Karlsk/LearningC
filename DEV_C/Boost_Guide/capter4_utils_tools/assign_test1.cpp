#include <string>                   //标准字符串类
#include <iostream>                 //标准输入输出
#include <vector>                   //标准向量容器
#include <set>                      //标准集合容器
#include <map>                      //标准映射容器
#include <algorithm>                //标准算法
using namespace std;                //打开标准库的命名空间

#include <boost/assign.hpp>
using namespace boost::assign;

int main(int argc, char const *argv[])
{
    vector<int> v;                  //标准向量容器
    v += 1,2,3,4,5, 6*6;            //用“+=”，“，”填入数据

    for (auto i : v)
    {
        cout << i << ", ";
    }
    cout << endl;
    

    set<string> s;                  //标准集合容器
    s += "c", "cpp", "lua", "swift";//用“+=”，“，”填入数据

    for (auto i : s)
    {
        cout << i << ", ";
    }
    cout << endl;

    map<int,string> m;              //标准映射容器
    m += make_pair(1,"one"), make_pair(2,"two");
    for (auto i : m)
    {
        cout << i.first << " " << i.second << ", ";
    }
    cout << endl;

    return 0;
}


