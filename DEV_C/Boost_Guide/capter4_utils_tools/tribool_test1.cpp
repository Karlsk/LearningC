#include <string>                   //标准字符串类
#include <iostream>                 //标准输入输出
#include <vector>                   //标准向量容器
#include <set>                      //标准集合容器
#include <map>                      //标准映射容器
#include <algorithm>                //标准算法
using namespace std;                //打开标准库的命名空间

#include<boost/assign.hpp>
using namespace boost::assign;

#include <boost/logic/tribool.hpp>
using namespace boost;

int main(int argc, char const *argv[])
{
    tribool tb(true);               //值为true的tribool
    tribool tb2(!tb);               //值为false

    if(tb)
    {   cout << "true" << endl; }   //tb == true

    tb2 = indeterminate;
    assert(indeterminate(tb2));
    cout << tb2.indeterminate_value << endl;

    if(tb2 == indeterminate)
   {   cout << "indeterminate" << endl; }   //tb == indeterminate值比较无意义，不会执行
    if(indeterminate(tb2))
   {   cout << "indeterminate" << endl; }   //tb == true

   cout << (tb2.indeterminate_value || true) << endl;
   cout << (tb2.indeterminate_value && false) << endl;




    return 0;
}
