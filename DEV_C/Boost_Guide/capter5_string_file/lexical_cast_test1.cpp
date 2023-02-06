#include <string>                   //标准字符串类
#include <iostream>                 //标准输入输出
#include <vector>                   //标准向量容器
#include <set>                      //标准集合容器
#include <map>                      //标准映射容器
#include <algorithm>                //标准算法
using namespace std;                //打开标准库的命名空间

#include <boost/lexical_cast.hpp>
using namespace boost;

int main(int argc, char const *argv[])
{
    int x = lexical_cast<int>("100");
    long y = lexical_cast<long>("2000");

    float pai = lexical_cast<float>("3.14159e5");
    double e = lexical_cast<double>("2.71828");
    double r = lexical_cast<double>("1.414,x",5);           //C字符串->double

    cout << r << endl;

    string str = lexical_cast<string>(456);

    cout << lexical_cast<string>(0.618) << endl;
    cout << lexical_cast<string>(0x10) << endl;             //十六进制整数转字符串
    cout << lexical_cast<bool>("1") <<  endl;
    try                                                     //所有都是非法的
    {
        cout << lexical_cast<int>("0x100") <<endl;
        cout << lexical_cast<double>("HelloWorld") <<endl;
        cout << lexical_cast<long>("1000L") <<endl;
        cout << lexical_cast<bool>("false") <<endl;
    }
    catch(bad_lexical_cast& e)
    {
        cout << "error: " << e.what() << endl;
    }

    return 0;
}
