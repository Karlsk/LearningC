#include <string>                   //标准字符串类
#include <iostream>                 //标准输入输出
#include <vector>                   //标准向量容器
#include <set>                      //标准集合容器
#include <map>                      //标准映射容器
#include <algorithm>                //标准算法
using namespace std;                //打开标准库的命名空间


#include <boost/system/error_category.hpp>
#include <boost/system/error_code.hpp>
using namespace boost;

class my_category : public error_category   //自定义错误类别
{
public:
    virtual const char* name() const BOOST_SYSTEM_NOEXCEPT
    {
        return "my category ";
    }

    virtual string message(int ev) const
    {
        string msg;
        switch (ev)
        {
        case 0:
            msg = "ok";
            break;
        
        default:
            msg = "some error";
            break;
        }
        return msg;
    }
};

int main(int argc, char const *argv[])
{
    my_category  my_cat;
    error_code ec(10,my_cat);       //错误码10，自定义错误类别
    cout << ec.value() << ec.message() << endl;

    ec = error_code(10,system_category());
    cout << ec.value() << ec.message() << endl;

    return 0;
}
