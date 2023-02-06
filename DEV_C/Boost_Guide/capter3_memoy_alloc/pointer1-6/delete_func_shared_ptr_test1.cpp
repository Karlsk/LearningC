#include <string>                   //标准字符串类
#include <iostream>                 //标准输入输出
#include <vector>                   //标准向量容器
#include <set>                      //标准集合容器
#include <map>                      //标准映射容器
#include <algorithm>                //标准算法
using namespace std;                //打开标准库的命名空间

#include <boost/shared_ptr.hpp>
#include <boost/make_shared.hpp>

class socket_t{};                     //socket类

socket_t* open_socket()               //打开socket
{
    cout << "Open Socket!!!" <<  endl;
    return new socket_t;
}

void close_socket(socket_t *s)        //关闭socket
{
    cout << "Close Socket!!!" << endl;
    // ...                              其他操作，释放资源
    delete s;
}

int main(int argc, char const *argv[])
{
    socket_t *s = open_socket();
    boost::shared_ptr<socket_t> p(s,close_socket);      //传入删除器
    // 或者 boost::shared_ptr<socket_t> p(s,&close_socket);      //传入删除器

    return 0;
}
