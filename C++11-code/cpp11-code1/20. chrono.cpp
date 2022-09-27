#include <iostream>
#include <chrono>
using namespace std;
using namespace chrono;

#if 1
// 1. 时间间隔 duration
void durationTest()
{
    // 1. 通过chrono命名空间提供的类型来表示时,分,秒,毫秒,微妙,纳秒
    chrono::hours h(1);
    chrono::minutes m(1);
    chrono::seconds s(3000);
    chrono::milliseconds mils{ 3 };
    chrono::microseconds mics(100);
    chrono::nanoseconds ns(200);
    duration<int, ratio<60 * 60,9>> h111(3);

    // 2. 通过构造函数来创建一个时间间隔
    // 3000 秒
    chrono::duration<int, ratio<1000>> ks(3);
    // 6.6 秒
    chrono::duration<double> ds(6.6);
    // 有3.5个时钟周期, 每个时钟周期时长是 1/30 秒
    chrono::duration<double, ratio<1, 30>> hz(3.5);
    cout << ds.count() << endl;
    cout << ks.count() << endl;
}

// 2. 时间间隔的算术运算
void durationOPTest() 
{
    // 时间周期不同: 
    // 1. 找到分子的最大公约数, 分母的最小公倍数
    // 2. 得到新的时间周期, 基于这个新的周期进行算术运算
    chrono::duration<int, ratio<60, 1>> t1(10);
    //chrono::minutes t1(10);
    chrono::duration<int, ratio<1, 1>> t2(60);
    //chrono::seconds t2(60);
    chrono::duration<int, ratio<1, 1>> t3 = t1 - t2;
    //auto t3 = t1 - t2;
    cout << t3.count() << endl;

    chrono::duration<double, ratio<9, 7>> d1(3);
    chrono::duration<double, ratio<6, 5>> d2(1);
    // d1 和 d2 统一之后的时钟周期
    chrono::duration<double, ratio<3, 35>> d3 = d1 - d2;
    auto d4 = d1 - d2;
    cout << d3.count() << endl;
}

// 3. 系统时钟
void systemClockTest()
{
    // 新纪元1970.1.1 8:00:00时间
    system_clock::time_point epoch;

    // 新纪元1970.1.1时间 + 1天
    using day = duration<int, ratio<60 * 60 * 24>>;
    system_clock::time_point epoch1(day(1));

    // 新纪元1970.1.1时间 + 10天
    system_clock::time_point epoch2(day(10));

    // 系统当前时间
    system_clock::time_point today = system_clock::now();

    // 转换为time_t时间类型
    // 今天
    time_t tm = system_clock::to_time_t(today);
    cout << "今天的日期: " << ctime(&tm) << endl;

    // 明天
    time_t tm1 = system_clock::to_time_t(today + day(1));
    cout << "明天的日期: " << ctime(&tm1) << endl;

    // 新纪元
    time_t tm2 = system_clock::to_time_t(epoch);
    cout << "新纪元的日期: " << ctime(&tm2) << endl;

    // 新纪元+1
    time_t tm3 = system_clock::to_time_t(epoch1);
    cout << "新纪元的日期 + 1: " << ctime(&tm3) << endl;

    // 新纪元+10
    time_t tm4 = system_clock::to_time_t(epoch2);
    cout << "新纪元的日期 + 10: " << ctime(&tm4) << endl;
}

// 4. 固定的时钟
// 测试某一段程序的执行效率，可以计算它执行期间消耗的总时长
void steadyClockTest()
{
    // 获取开始时间点
    steady_clock::time_point start = steady_clock::now();
    // 执行业务流程
    cout << "print 1000 stars ...." << endl;
    for (int i = 0; i < 1000; ++i)
    {
        cout << "*";
    }
    cout << endl;
    // 获取结束时间点
    steady_clock::time_point last = steady_clock::now();
    // 计算差值
    auto dt = last - start;
    cout << "总共耗时: " << dt.count() << "纳秒" << endl;
}

// 5. duration_cast 使用
void durationCastTest()
{
    // [时钟周期] 源周期可以被目标周期整除 
    // 分钟 -> 小时
    hours h = duration_cast<hours>(minutes(60));
    cout << h.count() << endl;

    // 小时 -> 分钟
    minutes m = hours(1);
    cout << m.count() << endl; // 60

    // [时钟周期数量的类型] 整形和浮点型时长转换
    // 整形 -> 浮点型
    duration<double> dd = seconds(3);
    cout << dd.count() << endl;
    using ddd = duration<double>;

    // 浮点型 -> 整形
    seconds ss = duration_cast<seconds>(ddd(3.5));
    cout << ss.count() << endl;

    duration<int, ratio<1, 100>> d1(100);
    duration<double, ratio<1, 1000>> d2(20.55);

    duration<int, ratio<1, 100>> d3 = d2;   // error
    duration<double, ratio<1, 1>> d4 = d1;
}

// 6. time_point_cast 使用
using Clock = chrono::system_clock;
template<typename Duration>
using TimePoint = time_point<Clock, Duration>;

void timePointCaseTest()
{
    // 1. 基于秒的时间点
    TimePoint<seconds> mPoint(seconds(1));
    // 2. 基于毫秒的时间点
    TimePoint<milliseconds> milPoint(milliseconds(1234));

    // s -> ms 1
    TimePoint<milliseconds> ms = mPoint;

    // ms -> s
    TimePoint<seconds> ss = time_point_cast<seconds>(milPoint);
}


int main()
{
    systemClockTest();
	return 0;
}
#endif