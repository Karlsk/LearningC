/*操做成员变量*/
#include <string>                   //标准字符串类
#include <iostream>                 //标准输入输出
#include <vector>                   //标准向量容器
#include <set>                      //标准集合容器
#include <map>                      //标准映射容器
#include <algorithm>                //标准算法
#include <assert.h>
using namespace std;                //打开标准库的命名空间

#include <boost/bind.hpp>

struct point                        //二维点类
{
    int x,y;
    point(int a = 0, int b = 0) : x(a),y(b) {}
    void print()
    {   cout << "(" << x << "," << y << ")" << endl; }
};

int main(int argc, char const *argv[])
{
    vector<point> v(10);
    for_each(v.begin(),v.end(),boost::bind(&point::print,_1));

    vector<point> v1 = { point(1,2),point(4,6)};
    vector<int> v2(2);
    vector<int> v3(2);
    

    transform(v1.begin(), v1.end(), v2.begin(), boost::bind(&point::x,_1));
    transform(v1.begin(), v1.end(), v3.begin(), boost::bind(&point::y,_1));


    for (auto x:v2)
    {
        cout << x << ", ";
    }
    cout << endl;
    for (auto x:v3)
    {
        cout << x << ", ";
    }
    cout << endl;
    
    typedef pair<int,string> pair_t;
    pair_t p(123,"string");

    cout << boost::bind(&pair_t::first,p)() << endl;
    cout << boost::bind(&pair_t::second,p)() << endl;

    int x = 17, y = 10;
    cout << boost::bind(std::greater<int>(),_1,10)(x) << endl;          //检查 x > 10
    cout << boost::bind(std::plus<int>(),_1,_2)(x,y) << endl;           //执行x+y
    cout << boost::bind(std::modulus<int>(),_1,3)(x) << endl;           //执行x%3

    struct func
    {
        int operator()(int a, int b)
        {
            return a + b;
        }
    };

    cout << boost::bind<int>(func(),_1,_2)(10,20) <<  endl;


    return 0;
}
