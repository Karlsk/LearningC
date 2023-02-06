#include <string>                   //标准字符串类
#include <iostream>                 //标准输入输出
#include <vector>                   //标准向量容器
#include <set>                      //标准集合容器
#include <map>                      //标准映射容器
#include <algorithm>                //标准算法
using namespace std;                //打开标准库的命名空间

#include <boost/shared_ptr.hpp>


int main(int argc, char const *argv[])
{
    boost::shared_ptr<int> sp1 (new int(10));           //一个指向整数的shared_ptr
    assert(sp1.unique());                               //现在shared_ptr是指针的唯一持有者

    boost::shared_ptr<int> sp2 = sp1;                   //第二个shared_ptr，拷贝构造函数
    assert(sp2 == sp1 && sp1.use_count() == 2);         //两个shared_ptr相等，指向同一个对象，引用计数为2
    assert(!sp1.unique());

    *sp2 = 100;
    assert(*sp1 == 100);                                //另一个shared_ptr也被修改

    sp1.reset();
    assert(!sp1);                                       //sp1不在持有任何指针(空指针)
    assert(sp2.unique());                                       
    cout << "unique: " << sp2.unique() << " count: " << sp2.use_count() << endl;  
    return 0;
}
