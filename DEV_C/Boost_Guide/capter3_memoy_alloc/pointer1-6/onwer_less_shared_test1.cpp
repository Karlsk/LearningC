#include <string>                   //标准字符串类
#include <iostream>                 //标准输入输出
#include <vector>                   //标准向量容器
#include <set>                      //标准集合容器
#include <map>                      //标准映射容器
#include <algorithm>                //标准算法
using namespace std;                //打开标准库的命名空间

#include <boost/shared_ptr.hpp>
#include <boost/make_shared.hpp>
#include <boost/smart_ptr/owner_less.hpp>

int main(int argc, char const *argv[])
{
    typedef boost::shared_ptr<int> int_ptr;
    typedef boost::owner_less<int_ptr> int_ptr_less;

    int_ptr p1(new int(10));
    int n = 20;
    int_ptr p2(p1, &n);            //别名构造函数

    assert(!int_ptr_less()(p1,p2) && !int_ptr_less()(p2,p1));   //两者既不大于，也不小于，既相等

    typedef set<int_ptr> int_set;
    int_set s;

    s.insert(p1);                   //插入两个元素，应为相同，所以第二次不会插入
    s.insert(p2);
    assert(s.size() == 1);          //实际容器里只有一个元素
    assert(p1.get() != p2.get());

    cout << *p1 << endl;
    cout << *p2 << endl;

    return 0;
}
