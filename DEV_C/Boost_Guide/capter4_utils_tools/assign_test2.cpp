#include <string>                   //标准字符串类
#include <iostream>                 //标准输入输出
#include <vector>                   //标准向量容器
#include <set>                      //标准集合容器
#include <map>                      //标准映射容器
#include <algorithm>                //标准算法
using namespace std;                //打开标准库的命名空间

#include<boost/assign.hpp>
using namespace boost::assign;

int main(int argc, char const *argv[])
{
    stack<int> stk = (list_of(1)(2),3).to_adapter();
    stk += 4,5,6;
    cout << "op stack:  ";
    for(;!stk.empty();)
    {
        cout << stk.top() << " ";
        stk.pop();
    }
    cout << endl;

    queue<string> q = (list_of("china")("uk")("us")).repeat(2,"russia").to_adapter();
    push(q)("germany");
    cout << "op queue:  ";
    for(;!q.empty();)
    {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;

    priority_queue<double> pq = (list_of(1.414),1.173,2.236).to_adapter();
    push(pq),3.414,2.71828;
    cout << "op priority_queue:  ";
    for(;!pq.empty();)
    {
        cout << pq.top() << " ";
        pq.pop();
    }
    cout << endl;

    return 0;
}
