#include <iostream>
#include <chrono>
using namespace std;
using namespace chrono;

#if 0
void durationTest()
{
    // hour
    duration<int, ratio<3600>> hour(1);
    chrono::hours h(1);
    // min
    duration<int, ratio<60>> min(1);
    chrono::minutes m(1);

    // sec
    duration<int> sec(1);
    duration<double> sec1(2.5);
    chrono::seconds sec2(1);
    // msec
    duration<int, ratio<1, 1000>> msec(1);
    chrono::microseconds msec1(2);
    // micro
    duration<int, ratio<1, 1000000>> micro(1);
    chrono::microseconds micsec(3);
    // nsec
    duration<int, ratio<1, 1000000000>> nsec(1);
    chrono::nanoseconds nn(5);

    cout << "count: " << sec1.count() << endl;
    cout << "count: " << nn.count() << endl;


    cout << "===============================" << endl;
    chrono::minutes m1(9);
    chrono::minutes m2(8);
    m1++;
    m2--;
    chrono::minutes m3 = m1 - m2;

    duration<int, ratio<60, 1>> t1(10);
    duration<int, ratio<1, 1>> t2(60);
    duration<int, ratio<1, 1>> t3 = t1 - t2;

    duration<double, ratio<9, 7>> d1(3);
    duration<double, ratio<6, 5>> d2(1);
    duration<double, ratio<3, 35>> d3 = d1 - d2;

    cout << m3.count() << endl;
    cout << "t3 count: " << t3.count() << endl;
    cout << "d3 count: " << d3.count() << endl;
}

void clockTest()
{
    // 创建一个时间点对象
    system_clock::time_point epoch;

    chrono::hours h(10 * 24);
    system_clock::time_point epoch1 = epoch + h;
    system_clock::time_point epoch2(epoch + h);

    // 当前的时间
    system_clock::time_point nowTime = system_clock::now();
    // 时间点 -> 时间段(单位秒)
    time_t allSec = system_clock::to_time_t(nowTime);
    cout << "当前的时间: " << ctime(&allSec) << endl;

    system_clock::time_point tp = system_clock::from_time_t(allSec);
}

void steadyClockTest()
{
    auto p1 = steady_clock::now();
    for (int i = 0; i < 1000; ++i)
    {
        cout << "*";
    }
    cout << endl;
    auto p2 = steady_clock::now();
    auto d1 = p2 - p1;
    cout << "count: " << d1.count() << endl;
}

void f()
{
    cout << "print 1000 stars ...." << endl;
    for (int i = 0; i < 1000; ++i)
    {
        cout << "*";
    }
    cout << endl;
}

void durationCastTest()
{
    // 分钟 -> 小时
    hours h = duration_cast<hours>(minutes(60));
    // 小时 -> 分钟
    minutes m1 = hours(1);

    // 浮点 -> 整形
    using mydouble = duration<double>;
    seconds ss = duration_cast<seconds>(duration<double>(2.5));
    // 整形 -> 浮点
    mydouble dd = seconds(9);

    duration<int, ratio<1, 100>> t1(100);
    duration<double, ratio<1, 1000>> t2(12.56);

    duration<int, ratio<1, 100>> t3 = duration_cast<duration<int, ratio<1, 100>>>(t2);
    duration<double, ratio<1, 1000>> t4 = t1;
}

template<typename Duration>
using MyTimePoint = time_point<system_clock, Duration>;

int main()
{
    // 基秒的时间点
    MyTimePoint<seconds> mPoint(seconds(1));
    MyTimePoint<milliseconds> millPoint(milliseconds(1));

    MyTimePoint<milliseconds> ms = mPoint;
    MyTimePoint<seconds> mms = time_point_cast<seconds>(millPoint);

    durationCastTest();
    return 0;
}
#endif