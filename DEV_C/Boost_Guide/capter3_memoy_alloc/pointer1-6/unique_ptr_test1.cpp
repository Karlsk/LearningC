#include <string>                   //标准字符串类
#include <iostream>                 //标准输入输出
#include <vector>                   //标准向量容器
#include <set>                      //标准集合容器
#include <map>                      //标准映射容器
#include <algorithm>                //标准算法
#include <memory>
#include <assert.h>
using namespace std;                //打开标准库的命名空间

#include <boost/smart_ptr/make_unique.hpp>
#include <boost/smart_ptr.hpp>
using namespace boost;


int main(int argc, char const *argv[])
{
    unique_ptr<int> up (new int);

    assert(up);
    *up = 10;
    cout << *up << endl;

    up.reset();

    assert(!up);                    //释放指针
    assert(up == nullptr);

    auto p = make_unique<int>(10);  //使用auto穿件unique_ptr对象
    assert(p && *p == 10);          //访问指针内容

    return 0;
}
