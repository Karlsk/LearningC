#include <string>                   //标准字符串类
#include <iostream>                 //标准输入输出
#include <vector>                   //标准向量容器
#include <set>                      //标准集合容器
#include <map>                      //标准映射容器
#include <algorithm>                //标准算法
using namespace std;                //打开标准库的命名空间

#include <boost/date_time/gregorian/gregorian.hpp>
#include <boost/date_time/posix_time/posix_time.hpp>

int main(void)
{
    boost::gregorian::date d1;                                  //一个无效的日期
    boost::gregorian::date d2(2010, 1, 1);
    boost::gregorian::date d3(2000, boost::date_time::Jan, 1);
    boost::gregorian::date d4(d2);
    boost::gregorian::date d5 = boost::gregorian::from_string("1999-12-31");
    boost::gregorian::date d6(boost::gregorian::from_string("2015/1/1"));
    boost::gregorian::date d7 = boost::gregorian::from_undelimited_string("20001118");

    assert(d4 == d2);
    assert(d3 < d4);
    assert(d1 == boost::gregorian::date(boost::gregorian::not_a_date_time));
    printf("ALL PASS !!!\n");

    cout << boost::gregorian::day_clock::local_day() << " " << boost::gregorian::day_clock::universal_day() << " " 
    << boost::gregorian::date(boost::gregorian::max_date_time) << endl;

    using namespace boost::gregorian;

    date d8(2017,6,1);

    date::ymd_type ymd = d8.year_month_day();
    cout << " " << ymd.year << " " << ymd.month << " " << ymd.day << endl;

    cout << d8.day_of_week() << endl;            //date的星期数
    cout << d8.day_of_year() << endl;            //date是当年的第几天
    assert(d8.end_of_month() == date(2017,6,30));
    cout << d8.end_of_month() <<endl;           //返回当月最后一天的date对象

    cout << date(2015,1,10).week_number() << endl;      //返回date所在的周是当年的第几周（0-53）
    cout << date(2016,1,10).week_number() << endl;
    cout << date(2017,1,10).week_number() << endl;
    // cout << date(2017,1,3).week_number() << endl;

    
//日期输出
    date d9(2017,1,23);

    cout << to_simple_string(d9) << endl;           //转换为YYYY-mmm-DD的格式，mmm为字母
    cout << to_iso_string(d9) << endl;              //转换为YYYMMDD的数字串格式
    cout << to_iso_extended_string(d9) << endl;     //转换为YYYY-MM-DD的数字串格式

    
    return 0;
}