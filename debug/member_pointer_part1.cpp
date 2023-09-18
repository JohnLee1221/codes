#include <thread>
#include <iostream>
using namespace std;

typedef void(*fn)(char*,int);

void ff(char* p, int num)
{
	//输出缓存区的大小
	for (int i =0;i<num;++i)
	{
		cout << p[i] << endl;
	}
}

int main()
{
	fn f1= ff;
  std::cout<< "test" <<std::endl;
	//测试下多线程内存管理
	std::shared_ptr<std::thread> thr1;
	thr1.reset(new std::thread([&f1,&thr1]() {
		std::this_thread::sleep_for(std::chrono::seconds(3));
		//注意：此处必须定义释放器，即后面的lambda。以为默认使用的释放是调用的delete。当new[]，delet[]，才是正确的，否则会资源泄漏
		auto p = std::shared_ptr<char>(new char[10], [](char *p) {cout << "删除对象" << endl; delete[]p; });
		//需要注意的是，当p出了这个{}作用域之后，资源便会释放。如果不想释放，可以在外面申请一个智能指针，在此处进行赋值。这样，
		//当外面指针出作用域的时候，资源才会释放
		for (int i =0;i<10;++i)
		{
			//获取智能指针的裸指针，来操作缓存区
			*(p.get() + i) = '0'+i;
		}
		f1(p.get(), 10);
		thr1.reset();
	}));
	thr1->detach();

    return 0;
}
