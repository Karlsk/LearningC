#include <string>                   //标准字符串类
#include <iostream>                 //标准输入输出
#include <vector>                   //标准向量容器
#include <set>                      //标准集合容器
#include <map>                      //标准映射容器
#include <algorithm>                //标准算法
using namespace std;                //打开标准库的命名空间

#include <boost/lexical_cast.hpp>
using namespace boost;

class demo_class
{
    friend std::ostream& operator<<(std::ostream& os, const demo_class& x)
    {
        os << "demo class Name";
        return os;
    }
};

//提取为模版类
template<typename T>
struct outable
{
    friend std::ostream& operator<<(std::ostream& os, const T& x)
    {
        os << typeid(T).name();         //使用typeid操作符，输出类型名称
        return os;
    }
};

class demo_class_new : public outable<demo_class_new>{};

int main(int argc, char const *argv[])
{
    demo_class_new dsn;
    demo_class ds; 
    cout << lexical_cast<string>(ds) << endl;
    cout << lexical_cast<string>(dsn) << endl;
    return 0;
}
