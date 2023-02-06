#include <string>                   //标准字符串类
#include <iostream>                 //标准输入输出
#include <vector>                   //标准向量容器
#include <set>                      //标准集合容器
#include <map>                      //标准映射容器
#include <algorithm>                //标准算法
using namespace std;                //打开标准库的命名空间

#include <boost/optional.hpp>
using namespace boost;


int main(int argc, char const *argv[])
{
    optional<int> op1;                  //一个未初始化的optional对象
    optional<int> op2(none);            //使用none，赋予其未初始化的值

    assert(!op1);                       //bool测试
    assert(op1 == op2);                 //比较两个optional对象

    assert(op1.value_or(253) == 253);   //获取默认值
    cout << op1.value_or_eval([](){return 874;}) <<endl;    //使用函数对象，用lambel表达式定义函数对象

    optional<string> ops("test");       //初始化为字符串test
    cout << *ops << endl;   

    ops.emplace("monado",3);            //就地创建一个字符串，没有拷贝代价  
    assert(*ops == "mon");              //只使用了前三个字符
    cout << *ops << endl;

    vector<int> v(10);
    optional<vector<int>&> opv(v);      //容纳一个容器的引用
    assert(opv);                        //bool转型

    opv -> push_back(5);
    assert(opv->size() == 11);

    opv = none;                         //置为未初始化状态
    assert(!opv);                       //此时为无效值

    return 0;
}
